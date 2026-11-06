# 宋子浩的嵌入式学习仓库

- 姓名：宋子浩
- 组别：VINCI 嵌入式组（一纳）
- 用途：记录 C/C++ 与 STM32 的学习笔记和代码，每两三天推送一次。

## 目录

| 路径 | 内容 |
| --- | --- |
| `cpp/01-pointers.md` | 指针笔记：地址、`&`/`*`、空指针、数组名、传指针改值 |
| `cpp/src/01_pointer_basics.cpp` | 笔记配套的可运行示例 |

## 编译运行

```bash
g++ -std=c++17 cpp/src/01_pointer_basics.cpp -o a
./a
```

## 进度

- 2026-11-02：C++ 指针（笔记 + 示例代码）
- 待补：C++ 生命周期、结构体；STM32 GPIO / EXTI / NVIC 实践工程（Keil）
