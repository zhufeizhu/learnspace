#include <iostream>
#include <vector>
#include <type_traits>
#include <initializer_list>



template<typename T,bool enable = std::is_floating_point<T>::value>
void test2(T& t){
    std::cout<<"this is default"<<std::endl;
}

template<typename T>
void test2<true>(T& t){
    std::cout<<"this is float"<<std::endl;
}

template<typename T>
void test2<false>(T& t){
    std::cout<<"this is not float"<<std::endl;
}

template<typename T,T...ints>
void print(std::integer_sequence<T,ints...>){
    auto list = {([&]{std::cout<<ints<<std::endl;}(),0)...};
}

//元函数
template<int N>
struct Add{
    static const int value = N * Add<N-1>::value;
};

//通过特化来实现判断
template<>
struct Add<1>{
    static const int value = 1;
};


int main(){
    float p = 1;
    test2(p);
}