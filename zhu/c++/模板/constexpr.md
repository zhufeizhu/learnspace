## constexpr

可以用来修饰函数 标明当前函数在编译器执行完成 在c++11仅支持函数有一个return的返回值 在c++14时支持常规的函数写法

如求n的阶乘 使用`constexpr`来在编译器执行计算 
- 在c++11的版本代码如下
```c++
constexpr int multi(int n){
    return (n == 1)?(1:n*multi(n-1));
}
```
- 在c++14的版本代码如下
```c++
constexpr int multi(int n){
    if(n == 1){
        return 1;
    }else{
        return n * multi(n-1);
    }
}
```