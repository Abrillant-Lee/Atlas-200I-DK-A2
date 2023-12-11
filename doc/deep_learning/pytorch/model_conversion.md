### 1、Pytorch部署

#### 使用ATC工具转换pytroch的pt模型文件

<details><summary>🚀pt模型转换为onnx模型文件</summary>

- 首先我们需要准备一个训练好的pt模型文件，假设我们已经准备好了。

- 接着我们需要提供一个示例输入，其形状应与你的**模型期望的输入形状相匹配。**

- 第一步：导入onnx的包
****
  ```python
  import torch
  import torch.onnx as onnx
  import torch.nn as nn
  ```

- 如果没有onnx的包，在终端输入以下命令（如果在类似于jupyter notebook中，在前面加上一个！）

  ```
  pip install onnx
  ```

- 第二步：先定义你训练的模型，然后创建模型实例

  ```python
  class LSTM(nn.Module):
      def __init__(self, input_size=1, hidden_layer_size=100, output_size=1):
          super().__init__()
          ......（省略）

      def forward(self, input_seq):
          ......（省略）

  # 创建LSTM模型实例
  model = LSTM()
  ```

- 第三步：# 加载预训练的模型参数（如果是.pt格式的文件,这里的pt文件保存的时模型的状态字典）

  > 如果pt文件保存的是LSTM的示例，需要将保存实例的pt文件变为保存状态字典的pt文件

  ```python
  torch.save(model.state_dict(), "./model.pt") # model.state_dict()表示获取模型的状态字典，它包含了模型的所有参数和对应的权重。
  state_dict = torch.load("./model.pt")
  model.load_state_dict(state_dict)
  ```

- 第四步：创建训练输入张量

  ```python
  test_input = [1,2,3,4] # 这里是你的训练输入的格式，我的是列表形式
  test_input_tensor = torch.FloatTensor(test_input[-2:]) # 转化为张量
  ```

- 第五步：导出模型为ONNX格式

  ```python
  output_path = "./model.onnx"
  torch.onnx.export(model, seq, output_path)

  print("模型已成功导出为ONNX格式：", output_path)
  ```

  - 示例输出（仅供参考）

  ```
  模型已成功导出为ONNX格式： /content/drive/MyDrive/ETS_data/model.onnx
  <ipython-input-4-f45c12d9d0f8>:11: TracerWarning: Using len to get tensor shape might cause the trace to be incorrect. Recommended usage would be tensor.shape[0]. Passing a tensor of different shape might lead to errors or silently give incorrect results.
  lstm_out, self.hidden_cell = self.lstm(input_seq.view(len(input_seq) ,1, -1), self.hidden_cell)
  <ipython-input-4-f45c12d9d0f8>:12: TracerWarning: Using len to get tensor shape might cause the trace to be incorrect. Recommended usage would be tensor.shape[0]. Passing a tensor of different shape might lead to errors or silently give incorrect results.
  predictions = self.fc(lstm_out.view(len(input_seq), -1))
  ```

</details>

<details><summary>🚀onnx模型文件转换为om模型文件</summary>

- 首先我们在上面已经将pt文件转化为onnx文件，这里我们是在本机进行

- 第一步：将onnx文件传输到昇腾开发板上（这里我使用scp命令）

  ```
  scp ./model.onnx root@10.0.0.1:/pytroch
  ```

- 第二步：使用ATC工具将onnx转化为om（我这里的昇腾型号是Ascend310B1）

  ```
  atc --model=./model.onnx --framework=5 --output=/root --soc_version=Ascend310B1
  ```

- 示例输出（仅供参考）
  ```
  ATC run success
  ```

</details>

- 正在更新中......

