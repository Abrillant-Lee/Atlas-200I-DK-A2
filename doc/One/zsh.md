### 2、Zsh美化😊😊]

> 由于本指南不使用 oh-my-zsh ,因此使用另一个 Zsh 框架 zim 安装 powerlevel10k。


<details><summary>🚀安装zsh终端</summary>

- 安装 zsh

  ```
  yum install zsh
  ```

</details>

<details><summary>🚀配置powerlevel10k</summary>

- 安装 zim

  ```
  curl -fsSL https://raw.githubusercontent.com/zimfw/install/master/install.zsh | zsh
  ```

- 编辑 Zsh 配置文件 ~/.zimrc ：

  ```
  vim ~/.zimrc

  # 在文件最后加入下面的一行文字，以添加 powerlevel10k 模块，然后退出。
  zmodule romkatv/powerlevel10k

  ```

- Start zsh!
  ```
  zsh
  ```

</details>

<details><summary>🚀配置字体font</summary>

> 在此时配置时，很多图标符号看不到，因为 powerlevel10k 中包含许多特殊图标符号，需要与之兼容的字体， 由于我们是用远程连接来使用昇腾的终端环境，所以字体依托的是电脑终端的字体

- 安装nerd fonts字体
>Nerd Fonts是一种用于编程和终端环境的字体集合，包含了大量的图标和符号，可以帮助开发人员更好地阅读和编辑代码。

- 打开[Nerd Fonts](https://github.com/ryanoasis/nerd-fonts)  github主仓库，点击releases，进入后选择想要的字体，这里推荐使用DroidSansM Nerd Font。

- 解压缩下载的字体文件。

- 右键单击字体文件，选择“安装”选项。

- 在终端或代码编辑器中选择新安装的字体。

</details>
