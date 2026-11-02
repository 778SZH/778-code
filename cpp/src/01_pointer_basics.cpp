// 指针最基础的几件事
// 编译： g++ -std=c++17 01_pointer_basics.cpp -o a   然后 ./a
#include <iostream>

int main() {
    // 1. 指针里存的是地址
    int a = 10;
    int* p = &a;

    std::cout << "a 的值       = " << a << "\n";
    std::cout << "a 的地址     = " << &a << "\n";
    std::cout << "p 里存的地址 = " << p << "  （和上面一样）\n";
    std::cout << "*p 取到的值  = " << *p << "  （就是 a 的值）\n";
    std::cout << "\n";

    // 2. 顺着指针改值
    *p = 20;
    std::cout << "执行 *p = 20 之后，a = " << a << "  （改的是 a，不是 p）\n";
    std::cout << "\n";

    // 3. 空指针：用之前要检查
    int* q = nullptr;
    if (q == nullptr) {
        std::cout << "q 是空指针，这时候千万不能写 *q\n";
    }
    int b = 5;
    q = &b;                       // 现在 q 指向 b 了
    std::cout << "q 指向 b，*q = " << *q << "\n";
    std::cout << "\n";

    // 4. 数组名就是第一个元素的地址
    int arr[3] = {1, 2, 3};
    int* r = arr;                 // 等于 &arr[0]
    std::cout << "r[0] = " << r[0] << "，r[1] = " << r[1] << "，r[2] = " << r[2] << "\n";
    std::cout << "*(r + 1) 和 r[1] 是一样的：" << *(r + 1) << "\n";
    std::cout << "\n";

    // 5. 传指针，函数才能改外面的变量
    auto addOne = [](int* n) { *n = *n + 1; };
    int x = 5;
    addOne(&x);
    std::cout << "传指针给函数加一，x 变成 " << x << "\n";

    return 0;
}
