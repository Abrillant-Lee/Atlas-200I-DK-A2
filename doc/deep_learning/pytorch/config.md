### 4、Pytorch😎😎
>PyTorch作为深度学习框架可以提供灵活、高效和便捷的深度学习研究和开发环境。

<details><summary>🚀安装pytorch</summary>

- 安装pytorch

  ```sh
  pip3 install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cpu
  ```

</details>

<details><summary>🚀验证pytorch</summary>

- 新建.py文件

  ```
  touch pytorch_test.py
  ```

- 使用nvim进入.py文件并写验证程序

  ```
  # 创建一个PyTorch张量并打印出来，如果这一步没有报错，那么就说明Pytorch已经成功安装。

  import torch

  # 打印PyTorch版本
  print(torch.__version__)

  # 创建一个张量
  x = torch.rand(5, 3)
  print(x)
  ```

- 运行程序

  ```
  python3 ./pytorch_test.py
  ```

- 安装成功示例

  ![](../../img/pytorch.jpg)

</details>

