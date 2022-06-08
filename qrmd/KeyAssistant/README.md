# AvZ KeyAssistant 按键辅助操作类 220607

## 简介

为常用的游戏操作建立按键映射，简化游戏操作。
### 关键词
手控 热键 快捷键 一键

## 运行环境

本插件针对 AvZ 220213 版本开发，不确保对其它 AvZ 版本的兼容性。

## 使用方法
将KeyAssistant.h 置于 AvZ/inc 目录后，编写脚本并运行即可。

在 Script() 外添加下面的代码以在编译时包含此库:
```c++
#include "KeyAssistant.h"
```

在 Script() 开头添加下面的代码以启用 tick_planter:
```c++
key_assistant.enable();
```

## 按键说明

### 按键快捷种植
1：在光标所在格子种植卡槽中的第1株植物；
2：在光标所在格子种植卡槽中的第2株植物；
3：在光标所在格子种植卡槽中的第3株植物；
4：在光标所在格子种植卡槽中的第4株植物；
5：在光标所在格子种植卡槽中的第6株植物；
6：在光标所在格子种植卡槽中的第6株植物；
7：在光标所在格子种植卡槽中的第7株植物；
8：在光标所在格子种植卡槽中的第8株植物；
9：在光标所在格子种植卡槽中的第9株植物；
0：在光标所在格子种植卡槽中的第0株植物。
### 按键快捷铲除
C：铲除光标处的植物，优先铲除南瓜头。
### 按键控制高级暂停
R：切换高级暂停状态
### 按键控制游戏运行速度
KeyAssistant将游戏运行速度倍率分为7个档位：0.1、0.2、0.5、1、2、5、10。
A：减慢游戏运行速度，即减小一个速度倍率档位；
D：加快游戏运行速度，即增大一个速度倍率档位；
S：恢复游戏运行速度，即将游戏运行速度倍率设为1。
### 按键控制女仆秘籍
X：当未启用女仆秘籍时，启用“舞王不前进且每帧尝试召唤舞伴”；启用了女仆秘籍时，停用女仆秘籍。