1. `__builtin_expect`
```c
    xx_unlikely(cond)	__builtin_expect((cond), 0)
    xx_likely(cond)	__builtin_expect(!!(cond), 1)
```
通常在if-else中使用 告诉编译器更可能(likely)执行到某分支 做汇编层次的代码优化(其实就是少执行了几个判断的汇编代码)

2. `cache_aligned`
```c
    struct task_queue{

    }__attribute(cache_lined);
```
使数据能够按照cacheline对齐 好处是
1. 可以防止数据跨cacheline 提高读写的效率
2. 在多线程中 因为cpu读写数据是按照cacheline来进行的 将数据按照cacheline对其 可以防止不同线程间的读写干扰
在`C++11`中也有类似的用法
```c++
    alignas(size) type var;
```
表明type类型的变量var按照大小为size对其 这里设置为cache_line即可按照cacheline对齐