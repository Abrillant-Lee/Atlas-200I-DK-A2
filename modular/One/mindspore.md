### 5、Mindspore😎😎

<details><summary>🚀安装Mindspore</summary>

> Ascend310,Linux-aarch64,python3.9

- 安装Mindspore

  ```sh
  pip install https://ms-release.obs.cn-north-4.myhuaweicloud.com/2.1.1/MindSpore/unified/aarch64/mindspore-2.1.1-cp39-cp39-linux_aarch64.whl --trusted-host ms-release.obs.cn-north-4.myhuaweicloud.com -i https://pypi.tuna.tsinghua.edu.cn/simple
  ```

</details>

<details><summary>🚀验证Mindspore</summary>

- 新建.py文件

  ```
  touch Mindspore_test.py
  ```

- 使用nvim进入.py文件并写验证程序

  ```
  # 创建一个MindSpore张量并打印出来，如果这一步没有报错，那么就说明MindSpore已经成功安装。
  import mindspore

  # 打印MindSpore版本
  print(mindspore.__version__)

  # 创建一个张量
  x = mindspore.Tensor([1.0, 2.0, 3.0])
  print(x)
  ```

- 运行程序

  ```
  python3 ./Mindspore_test.py
  ```

- 安装成功示例

  ![](../../img/Mindspore.jpg)

</details>

