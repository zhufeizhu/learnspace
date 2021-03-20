#include<stdio.h>

class A{
public:
    void func(){
        printf("this is a");
        return;
    };
    void func(int){
        printf("this is a");
        return;
    }
};

void func(){
    printf("this is a");
    return;
}

namespace F{
    void func(){
        printf("this is a");
        return;
    };

    class B{
    public:
        void func(){
            printf("this is a");
            return;
        };
    };
}

int main(){
    A a;
    a.func();
    a.func(1);
    F::B b;
    b.func();
    func();
    F::func();
    return 0;
}