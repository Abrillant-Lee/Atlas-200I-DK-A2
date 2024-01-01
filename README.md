<h1 align="center" >🎉Maker-IoT🚀Atlas-200I-DK-A2🎉</h1>

<div align="center">
👋🏼**此教程更偏向昇腾的Linux系统的操作**，请优先学习<a target="_blank" href="https://www.hiascend.com/document/detail/zh/Atlas200IDKA2DeveloperKit/23.0.RC2/lg/toctopics/topic_0000001698461113.html">昇腾文档</a>👋🏼

<br>

<div style="font-size:2.0em" align=center>
  <p>
  <a href="https://github.com/Maker-IoT-one/Atlas-200I-DK-A2/pulls"><img src="https://img.shields.io/badge/Pull%20Request-Click%20me-%23293241?style=flat-square&labelColor=%23293241&color=%233D5A80"></a>
  <a href="https://github.com/Maker-IoT-one/Atlas-200I-DK-A2/issues"><img src="https://img.shields.io/badge/Issues-Click%20me-%23293241?style=flat-square&labelColor=%23293241&color=%23EE6C4D"></a>
  <a href="https://github.com/Maker-IoT-one/Atlas-200I-DK-A2/stargazers"><img src="https://img.shields.io/badge/Stars-Click%20me-%23293241?style=flat-square&labelColor=%23293241&color=%23E0FBFC"></a>
  <a href="https://github.com/Maker-IoT-one/Atlas-200I-DK-A2/graphs/contributors"><img src="https://img.shields.io/badge/Members-Click%20me-%23293241?style=flat-square&labelColor=%23293241&color=%2398C1D9"></a>
  </p>
</div>

</div>

## 一、Getting Started 环境搭建

### [1、Clash代理🚀🚀🚀](./doc/network/clash.md)

> 在某些情况下，你可能需要配置代理来访问互联网。下面所有的配置都是在有代理的环境下进行，可以提高数百倍下载速度，尽量完成这一步，来提高开发效率。

### [2、Zsh美化😊😊](./doc/terminal/zsh.md)

> 🌺 爱美之心，人皆有之；美化终端不仅可以提升工作心情、增加个性化，同时也可以提高工作效率。本指南不使用 oh-my-zsh ,使用另一个 Zsh 框架 zim 来安装 powerlevel10k主题。
****
### [3、Neovim😍😍](./doc/editor/neovim.md)

>nvim是一款功能强大、高效、可定制的编辑器，适用于各种编程场景，可以帮助用户提高编辑效率。由于nvim的github官网没有arm版本的压缩包，即不支持Arm架构,所以在昇腾的Openerul镜像上通过压缩包安装是不行的，以下是通过编译下载的方式。

### [4、Pytorch😎😎](./doc/deep_learning/pytorch/config.md)
>PyTorch作为深度学习框架可以提供灵活、高效和便捷的深度学习研究和开发环境。

### [5、Mindspore😎😎](./doc/deep_learning/mindspore/config.md)
>MindSpore可以加速深度学习算法的研发和应用，其高效性、易用性和灵活性有助于提高模型的训练速度和精度。

### [6、OpenGauss🤔🤔🤔](./doc/database/opengauss.md)
>使用OpenGauss数据库可以提高企业级数据库的性能、可扩展性和安全性，同时支持多种应用场景。官方文档：https://docs-opengauss.osinfra.cn/zh/ ;以下采用最新版的单节点服务器安装

### [Finaly、环境搭建问题库🤡🤡🤡](./doc/questions/questions_one.md)

> 如果大家配置环境时遇到问题，刚开始就当了小丑，不过没关系，可以提交问题issus，我和小伙伴们将在此处更新大家遇到的经典、有意义的问题。

---

## 二、算法部署⚡⚡⚡

### [1、Pytorch部署⚡](./doc/deep_learning/pytorch/model_conversion.md)

### [Finally、算法部署问题库😭😭😭](./doc/questions/questions_two.md)

> 如果大家在部署算法环境时遇到问题，可以提交issus，我和小伙伴们将在此处更新大家遇到的问题。

---

## 三、深度学习之“推理代码”⚡⚡⚡
### [1、何为“推理”🤔？](./doc/deep_learning/explain.md)
> 作为整个模型部署中非常重要的一环，推理代码可以避免每次运行模型都需要训练的弊端，同时也会使模型部署推理更为轻松

### [2、pytorch框架的“推理”](./doc/deep_learning/pytorch/pytorch_predict.md)
> 现在开始第一章节，有关pytorch的撰写，里面包括pytorch框架下可以选择使用的模型文件的类型，以及到处和导入的方式。

---

## 四、玩转昇腾硬件(Shell)✌🏼✌🏼✌🏼

### [1、玩转GPIO](./doc/hardware/gpio.md)✌🏼
>GPIO（通用输入/输出）是一种通用引脚，可以由微控制器（MCU）或CPU控制，具有多种功能，包括高低电平输入检测和输出控制。

### [2、玩转串口](./doc/hardware/serial.md)✌🏼
>我们常常使用终端来与板卡进行交互， 而这个终端与板卡连接的众多方式之中，UART串口就是我们最常使用的方式之一。

### [3、玩转摄像头](./doc/hardware/camera.md)✌🏼
> 调用摄像头拍照、录制视频

### [4、玩转音频](./doc/hardware/audio.md)✌🏼
> 调用音频设备进行录音、播放录音

---

## 五、上下位机交互✨⭐🌟

> 上位机：昇腾，下位机：Hi3861

### [1、昇腾和小熊派串口通信✨](./doc/hardware/hi3861_serial.md)

- 正在更新中.........

---

## 六、昇腾与后端交互🤩🤩🤩
>后端：django、JavaWeb 数据库:昇腾的openGauss

### [1、django项目使用openGauss数据库](./doc/database/django.md)
既然以及装载好了openGauss，那就让django项目能够进行使用

- 正在更新中.........
---

# 🎉参与贡献🎉

<p align="center">
<!-- <img width="210" height="180" align="left" style="float: left; margin: 0 10px 0 0;" src="https://archlinuxstudio.github.io/ShellTutorial/bash.svg" alt="ArchLinuxStudio_ShellTutorial"/> -->
<img width="210" height="210" align="left" style="float: left; margin: 0 10px 0 0;" src="./img/IOT-水晶标.jpg" alt="ArchLinuxStudio_ShellTutorial"/>

<h2>本仓库隶属于梅科尔工作室IoT组</h2>

仓库的编写得到了梅科尔工作室IoT团队小伙伴们的积极参与，我们热切欢迎大家加入我们的交流群（群号：469363175），共同为这个仓库添砖加瓦，助力大家更好地开发昇腾，期待与您的合作开发！ <br>

Thank you to all the people who already contributed to Maker-IoT!

<a href="https://github.com/Abrillant-Lee/Atlas-200I-DK-A2/graphs/contributors">
<img src="./img/Abrillant-Lee.png"width=33>
<img src="./img/Ryanzhang.png"width=33>
<img src="./img/wei.png"width=33/>
<img src="./img/luosen.png"width=30/>
</a>
<br>
<br>
</p>





### [如何参与贡献🥳](./doc/contribute/become_a_contributor.md)
>如果你对这个开源项目非常感兴趣，并且你发现了其中的Issue并有能力解决它们，或者发现了其他问题并希望参与改进，那么点击标题，将告诉你如何成为一个贡献者。
