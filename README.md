# 学习笔记

## 2020.12.15 
**守护进程 进程组 会话 终端 `SIGHUP`**

## 2020.12.27
1. 学习了C++的单例类`Singleton`以及它的两种写法 其中静态类主要用在某个对象在全局仅能有一个实例的情况(实习期间参考wenpeng的写过一次)
   * 懒汉模式:类中为静态指针 保证了在未调用对应`getInstance`函数之前不会进行初始化 `.bbs`段仅保存了对应的指针
     * 好处是占用的内存很小 只有一个指针的大小
     * 坏处是不能保证线程安全 需要补充额外的代码进行保证

代码如下
```
    class Singleton{
    public:
        Singleton(const Singleton& ) = delete;
        static Singleton* getInstance(){
            lock()
            if (instance == NULL){
                instance = new Singleton();
            }
            unlock();
            return instance;
        }
    private:
        Singleton();
        static Singleton *instance;
    }
```
   * 饿汉模式：类中为静态对象 在调用`getInstance`前已经初始化完成 `.bbs`段存储的是对应的对象
     * 好处是不需要考虑线程安全的问题
     * 坏处是占用的空间较大
2. 下载了`Android`端的`github` 需要通过`GooglePlay`下载 国内的话可以从[这个网址](https://gitclone.com)下载 以后可以在手机上随时随地看代码了
3. 开始阅读`muduo`的`base`库代码 学习到了一些新的技巧
   1. C++线程安全注解: 和Java的注解类似 在编译器进行一些规定的语法分析 这里看的主要是`REQUIRE`和`GUARDED_BY`两个 具体用法参考[Thread Safety Analysis](http://clang.llvm.org/docs/ThreadSafetyAnalysis.html)
   2. 静态类的懒汉模式的另一种写法 通过`pthread_once`来实现,具体用法如下 该函数的大致功能就是 当前线程仅能有一次执行该函数 具体实现是通过`pthread_once_t`这个变量取不通值来实现的 初始必须要赋值为`PTHREAD_ONCE_INIT`
    ```
        pthread_one_t once = PTHREAD_ONCE_INIT;
        int pthread_once(pthread_once_t *once,void(*func)(void));
    ```
   
