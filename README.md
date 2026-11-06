# 宋子浩的算法学习仓库

- 姓名：宋子浩
- 组别：VINCI 算法组
- 用途：记录 C/C++、Linux 与 ROS2 的学习笔记和代码，每两三天推送一次。

## 目录

| 路径 | 内容 |
| --- | --- |
| `cpp/01-pointers.md` | C++ 指针笔记：地址、`&`/`*`、空指针、数组名、传指针改值 |
| `cpp/src/01_pointer_basics.cpp` | 指针笔记配套的可运行示例 |
| `ros2/01-环境搭建记录.md` | ROS2 Humble 在 WSL2 Ubuntu 22.04 上的安装过程与验证结果 |
| `ros2/verify_env.sh` | 一键自检脚本：两个节点互通、话题发布订阅、turtlesim 启动 |

## 怎么跑

```bash
# C++ 示例
g++ -std=c++17 cpp/src/01_pointer_basics.cpp -o a && ./a

# ROS2 环境自检（在 Windows 终端里执行）
wsl -d Ubuntu-22.04 -- bash /mnt/d/workspace/cpp-stm32-notes/ros2/verify_env.sh
```

## 进度

- 2026-11-02　C++ 指针：笔记 + 示例代码
- 2026-11-06　ROS2 Humble 装好并实测通过：273 个包，talker/listener 互通，turtlesim 正常启动
- 待办　C++ 生命周期、结构体、类与对象；自己写第一个 ROS2 节点（话题发布 + 订阅）
