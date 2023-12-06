

### [6、OpenGauss🤔🤔🤔](./modular/opengauss.md)


<details><summary>🚀获取安装包</summary>

- 从openGauss开源社区下载对应平台的安装包，对于个人开发者或非企业级环境，下载极简安装包（不安装OM等组件）即可。

  ```
  开源社区链接：https://opengauss.org/zh/download/
  ```

- 使用scp将安装文件复制到远程昇腾

  ```ash
  # 语法
  scp SourceFile user@host:directory/TargetFile

  # 示例
  scp ./.\openGauss-5.1.0-openEuler-64bit.tar.bz2  user@192.168.137.100:/home/user
  ```

</details>

<details><summary>🚀单节点服务器安装</summary>

- 创建用户组Family。

  ```
  groupadd Family
  ```

- 创建用户组Family下的普通用户me，并设置普通用户me的密码，密码建议设置为root。

  ```
  useradd -g Family me
  passwd me
  ```

- 使用me用户登录到openGauss包安装的主机，解压openGauss压缩包到安装目录（假定安装目录为/home/me/openGauss，请用实际值替换）。

  ```
  tar -jxf openGauss-x.x.x-操作系统-64bit.tar.bz2 -C /home/me/openGauss
  ```

- 假定解压包的路径为/home/me/openGauss,进入解压后目录下的simpleInstall。

  ```
  cd /home/me/openGauss/simpleInstall
  ```

- 执行install.sh脚本安装openGauss。

  ```
  # -w是指初始化数据库密码（gs_initdb指定），安全需要必须设置。
  sh install.sh  -w xxxx
  ```

- 安装完之后进入OpenGauss数据库

  ```
  gsql -d postgres
  ```

- 安装成功示例

  ![](./img/openGauss.jpg)

</details>

<details><summary>🚀远程连接</summary>
</details>

- 正在更新中......

