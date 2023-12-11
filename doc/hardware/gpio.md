## 1、GPIO子系统🚀

GPIO（通用输入/输出）是一种通用引脚，可以由微控制器（MCU）或CPU控制，具有多种功能，包括高低电平输入检测和输出控制。

## 2、GPIO工具介绍🚀
> 使用gpio_operate工具

`gpio_operate`工具用于设置GPIO管脚的输入与输出方向，也可将每个GPIO管脚独立的设为0或1
- gpio_operate命令必须使用root帐号执行。
- 支持设置的GPIO管脚如表1所示，以下管脚存在复用关系，使用前须将其复用为GPIO。

| 组号 | 管脚号 |
| --- | --- |
| 0 | 2，3，14，15，23，25 <br>第0组的第23个管脚为内部使用管脚，用于设置开发者套件的LED3状态指示灯。|
| 1 | 1，6 |
| 2 | 11，12，15，16，17，18，19，20，25，26，27，28 |
| 4 | 0 |
| 7 | 2，3，4，5，6，7 |

**<center>表1：昇腾GPIO口编号**</center>

## 3、控制GPIO（Shell）🚀

| 命令 | 功能 | 参数说明 |
| --- | --- | --- |
| gpio_operate -h | 获取gpio_operate命令帮助信息 | |
| gpio_operate get_value ***gpio_group gpio_pin***| 查询GPIO管脚值 |***gpio_group***  GPIO组号，取值为[0，8] <br> ***gpio_pin*** GPIO管脚号，取值为[0，31]|
|gpio_operate set_value ***gpio_group gpio_pin value*** | 设置GPIO管脚值 | ***gpio_group*** GPIO组号，取值为[0，8]<br> ***gpio_pin*** GPIO管脚号，取值为[0，31]<br> ***value*** GPIO管脚值，取值为[0，1]<br> 当GPIO管脚方向为输入方向时，不允许设置GPIO管脚值。|
| gpio_operate get_direction ***gpio_group gpio_pin*** | 用于查询GPIO管脚方向。 | ***gpio_group*** GPIO组号，取值为[0，8]<br> ***gpio_pin*** GPIO管脚号，取值为[0，31] |
| gpio_operate set_direction ***gpio_group gpio_pin direction*** | 用于设置GPIO管脚方向。 | ***gpio_group*** GPIO组号，取值为[0，8]<br> ***gpio_pin*** GPIO管脚号，取值为[0，31]<br> ***direction*** GPIO管脚方向，取值为[0，1]，其中0表示输入方向，1表示输出方向 |
