# 学习笔记

记录 C/C++、Linux、ROS2 与 OpenCV 的学习笔记和代码。

## 目录

| 路径 | 内容 |
| --- | --- |
| `cpp/01-pointers.md` | C++ 指针笔记：地址、`&`/`*`、空指针、数组名、传指针改值 |
| `cpp/src/01_pointer_basics.cpp` | 指针笔记配套的可运行示例 |
| `ros2/01-环境搭建记录.md` | ROS2 Humble 在 WSL2 Ubuntu 22.04 上的安装过程与验证结果 |
| `ros2/verify_env.sh` | 一键自检脚本：两个节点互通、话题发布订阅、turtlesim 启动 |
| `opencv/` | OpenCV 练习 6 题：读图信息、三色旗、ROI 共享/复制、二值化、滤波 + Canny、摄像头实时处理 |

## 怎么跑

```bash
# C++ 示例
g++ -std=c++17 cpp/src/01_pointer_basics.cpp -o a && ./a

# ROS2 环境自检（在 Windows 终端里执行）
wsl -d Ubuntu-22.04 -- bash /mnt/d/workspace/cpp-stm32-notes/ros2/verify_env.sh

# OpenCV 练习（VS 2022 + CMake，见 opencv/README.md）
cmake -S opencv -B opencv/build -G "Visual Studio 17 2022" -A x64
cmake --build opencv/build --config Release
```

## 进度

- 2026-11-02　C++ 指针：笔记 + 示例代码
- 2026-11-06　ROS2 Humble 装好并实测通过：273 个包，talker/listener 互通，turtlesim 正常启动
- 2026-11-15　OpenCV 练习 6 题：全部编译通过，ex1~ex5 实测输出正确，ex6 摄像头按键切换
- 待办　C++ 生命周期、结构体、类与对象；自己写第一个 ROS2 节点（话题发布 + 订阅）
