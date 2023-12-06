<details><summary>安装zsh终端</summary>

- 安装 zsh

  ```
  yum install zsh
  ```

</details>

<details><summary>配置powerlevel10k</summary>

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

