## 1、硬件接线

- 本教程采用的摄像头为： HIK 2K Camera（海康威视）<br>

- 将USB摄像头接入开发者套件任意一个空闲USB接口（USB 3.0 Type A）。

- 连接示例：

    <img src="../../img/camera.jpg" width ="400">

- 验证连接

  ```bash
  #查看usb设备
  lsusb

  #连接成功示例
  Bus 003 Device 003: ID 2bdf:028a SN0002 HIK 2K Camera
  ```

- 检测USB摄像头工作是否正常

  ```bash
  sudo v4l2-ctl -d /dev/video0 --all

  #成功示例
    Driver Info (not using libv4l2):
            Driver name   : uvcvideo
            Card type     : HIK 2K Camera: HIK 2K Camera
            Bus info      : usb-xhci-hcd.1.auto-1.1
            Driver version: 5.10.0
            Capabilities  : 0x84A00001
                    Video Capture
                    Metadata Capture
                    Streaming
                    Extended Pix Format
                    Device Capabilities
            Device Caps   : 0x04200001
                    Video Capture
                    Streaming
                    Extended Pix Format
    Priority: 2
    Video input : 0 (Input 1: ok)
    Format Video Capture:
            Width/Height      : 1280/960
            Pixel Format      : 'YUYV'
            Field             : None
            Bytes per Line    : 2560
            Size Image        : 2457600
            Colorspace        : Default
            Transfer Function : Default (maps to Rec. 709)
            YCbCr/HSV Encoding: Default (maps to ITU-R 601)
            Quantization      : Default (maps to Limited Range)
            Flags             :
    Crop Capability Video Capture:
            Bounds      : Left 0, Top 0, Width 1280, Height 960
            Default     : Left 0, Top 0, Width 1280, Height 960
            Pixel Aspect: 1/1
    Selection: crop_default, Left 0, Top 0, Width 1280, Height 960
    Selection: crop_bounds, Left 0, Top 0, Width 1280, Height 960
    Streaming Parameters Video Capture:
            Capabilities     : timeperframe
            Frames per second: 5.000 (5/1)
            Read buffers     : 0
                        brightness 0x00980900 (int)    : min=1 max=255 step=1 default=128 value=128
                        contrast 0x00980901 (int)    : min=1 max=255 step=1 default=128 value=128
                        saturation 0x00980902 (int)    : min=1 max=255 step=1 default=128 value=128
                                hue 0x00980903 (int)    : min=0 max=255 step=1 default=128 value=128
    white_balance_temperature_auto 0x0098090c (bool)   : default=0 value=1
  ```

## 2、拍照

### 方式一：使用 ffmpeg 从摄像头捕获一张图片

- 拍照命令

    ```bash
    ffmpeg -f v4l2 -video_size 640x480 -i /dev/video0 -vframes 1 output.jpg
    ```

- 命令详解

    - -f v4l2：设置输入格式为 Video4Linux2，这是 Linux 上用于处理视频流的框架。
    - -video_size 640x480：设置视频分辨率为 640x480。
    - -i /dev/video0：输入设备是 /dev/video0，这通常是第一个摄像头设备。
    - -vframes 1：只输出一帧，即一张图片。
    - output.jpg：输出文件是 output.jpg。

- 查看图片

    ```bash
    #安装 ImageMagick 和 ImageMagick-devel 包
    yum install -y ImageMagick ImageMagick-devel

    #显示图像
    dispaly output.jpg
    ```

- 演示视频

  ![](../../img/take_photo.gif)

## 3、录制视频

### 方式一：使用 ffmpeg 录制视频

- 录制视频命令

    ```bash
    ffmpeg -f v4l2 -s 640x480 -i /dev/video0 -t 10 output.mp4
    ```

- 命令详解
    - -f v4l2：设置输入格式为 Video4Linux2。
    - -s 640x480：设置视频分辨率为 640x480。
    - -i /dev/video0：输入设备是 /dev/video0。
    - -t 10：录制时间为10s
    - output.mp4：输出文件是 output.mp4。

- 播放视频

    ```bash
    ffplay output.mp4
    ```

- 演示视频

    ![](../../img/take_video.gif)



