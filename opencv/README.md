# OpenCV

环境：Visual Studio 2022 + OpenCV 4.13.0（预编译包）。

单个工程，各写成一个函数（`work1` 命名空间），`main.cpp` 里取消对应注释即可单独跑。

`CMakeLists.txt` 里的 `OpenCV_DIR` 指向本机 OpenCV 的 `build` 目录，先改成你自己的路径再编译：

```bash
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release
```

或在 Visual Studio 里「打开文件夹」选这个目录直接生成。编译后 `opencv_world*.dll` 和测试图 `sample.png` 会自动复制到 exe 旁，双击即可运行。

双击 exe 或命令行运行，`imshow` 弹窗后按任意键（第 6 题按 `q`）退出。只想看打印结果、不想弹窗，设环境变量 `OPENCV_NO_SHOW=1`。

| 函数 | 题目 |
|------|------|
| `work1::PictureViewer` | 1. 读图显示 + 打印宽/高/通道数/像素总数/每像素字节数 + 转灰度再打印 |
| `work1::FlagGenerator` | 2. 三色旗（ROI + setTo），`at<>()` 改 (250,80) 为白，打印前后 BGR |
| `work1::Cutting` | 3. 裁剪区域，验证 ROI 共享内存 vs `clone()` 复制 |
| `work1::CoveredWithBlackAndWhite` | 4. 灰度 + 阈值 60/120/180 + 手写双层循环二值化 + 白色像素统计 |
| `work1::Progression` | 5. 均值/高斯/中值滤波 + Canny 四种组合对比 |
| `work1::RealtimeCamera` | 6. 摄像头实时处理，按键 1/2/3/4 切模式，q 退出 |
