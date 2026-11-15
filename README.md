## C++ 指针

- `cpp/01-pointers.md` — 地址、`&`/`*`、空指针、数组名、传指针改值
- `cpp/src/01_pointer_basics.cpp` — 配套可运行示例

```bash
g++ -std=c++17 cpp/src/01_pointer_basics.cpp -o a && ./a
```

## ROS2

- `ros2/01-环境搭建记录.md` — Humble 在 WSL2 Ubuntu 22.04 上的安装与验证
- `ros2/verify_env.sh` — 一键自检脚本

```bash
wsl -d Ubuntu-22.04 -- bash ros2/verify_env.sh
```

## OpenCV

- `opencv/` — 读图信息、三色旗、ROI 共享/复制、二值化、滤波 + Canny、摄像头实时处理

```bash
cmake -S opencv -B opencv/build -G "Visual Studio 17 2022" -A x64
cmake --build opencv/build --config Release
```
