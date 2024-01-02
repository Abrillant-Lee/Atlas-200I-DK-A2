<h1 align="center" >🎉Maker-IoT🚀Atlas-200I-DK-A2🎉</h1>

<div align="center">
  <p>
    <strong>本仓库是梅科尔工作室IoT组成员们对昇腾的开发经验总结，教程更偏向昇腾的Linux系统的操作,旨在帮助大家更好地学习昇腾，欢迎大家加入我们的交流群（群号：469363175）</strong>
  </p>
</div>

<div align="center">
<a href="https://www.hiascend.com/"><img src="https://img.shields.io/badge/昇腾-官网-red.svg?style=flat-square"></a>
<a href="https://www.hiascend.com/document/detail/zh/Atlas200IDKA2DeveloperKit/23.0.RC2/lg/toctopics/topic_0000001698461113.html"><img src="https://img.shields.io/badge/昇腾-文档-blue.svg?style=flat-square"></a>
<a href="https://gitee.com/ascend"><img src="https://img.shields.io/badge/昇腾-Gitee-blueviolet.svg?style=flat-square"></a>
<a href="https://www.hiascend.com/forum/"><img src="https://img.shields.io/badge/昇腾-论坛-ff69b4.svg?style=flat-square"></a>
<a href="https://www.hiascend.com/developer"><img src="https://img.shields.io/badge/昇腾-开发者社区-8cf.svg?style=flat-square"></a>
</div>

<div style="font-size:2.0em" align=center>
  <p>

  ![GitHub stars](https://img.shields.io/github/stars/Abrillant-Lee/Atlas-200I-DK-A2?style=social)
  <a href="https://github.com/Maker-IoT-one/Atlas-200I-DK-A2/pulls"><img src="https://img.shields.io/badge/Pull%20Request-Click%20me-%23293241?style=flat-square&labelColor=%23293241&color=%233D5A80"></a>
  <a href="https://github.com/Maker-IoT-one/Atlas-200I-DK-A2/issues"><img src="https://img.shields.io/badge/Issues-Click%20me-%23293241?style=flat-square&labelColor=%23293241&color=%23EE6C4D"></a>
  <a href="https://github.com/Maker-IoT-one/Atlas-200I-DK-A2/stargazers"><img src="https://img.shields.io/badge/Stars-Click%20me-%23293241?style=flat-square&labelColor=%23293241&color=%23E0FBFC"></a>
  <a href="https://github.com/Maker-IoT-one/Atlas-200I-DK-A2/graphs/contributors"><img src="https://img.shields.io/badge/Members-Click%20me-%23293241?style=flat-square&labelColor=%23293241&color=%2398C1D9"></a>
  </p>

</div>


## 目录

- 一、Getting Started 环境搭建🚀🚀🚀
  - [1、Clash代理](#1clash代理)
  - [2、Zsh美化](#2zsh美化)
  - [3、Neovim](#3neovim)
  - [4、Pytorch](#4pytorch)
  - [5、Mindspore](#5mindspore)
  - [6、OpenGauss](#6opengauss)
  - [Finaly、环境搭建问题库🤡](#finaly环境搭建问题库)
- 二、算法部署⚡⚡⚡
  - [1、Pytorch部署](#1pytorch部署)
  - [Finally、算法部署问题库](#finally算法部署问题库)
- 三、深度学习之“推理代码”⚡⚡⚡
  - [1、何为“推理”？](#1何为推理)
  - [2、pytorch框架的“推理”](#2pytorch框架的推理)
- 四、玩转昇腾硬件(Shell)✌🏼✌🏼✌🏼
  - [1、玩转GPIO](#1玩转gpio)
  - [2、玩转串口](#2玩转串口)
  - [3、玩转摄像头](#3玩转摄像头)
  - [4、玩转音频](#4玩转音频)
- 五、上下位机交互✨⭐🌟
  - [1、昇腾和小熊派串口通信](./doc/hardware/hi3861_serial.md)

- 六、昇腾与后端交互
  - [1、django项目使用openGauss数据库](./doc/database/django.md)


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
