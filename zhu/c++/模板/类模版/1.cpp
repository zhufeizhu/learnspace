#include<vector>

template<typename U, size_t MaxSize>
class Stack{
public:
    Stack() = default;
    Stack(const Stack& );//这里与Stack(const Stack<U>&)是等价的
    Stack& operator=(const Stack&);
    void push(const U& elem);
    void pop();
    U& top() const;
    bool empty() const{
        return elems.empty();
    };
private:
    std::vector<U> elems;
    size_t size;
};

template<typename U, size_t MaxSize>
Stack<U,MaxSize>::Stack(const Stack& s){
    this->elems = std::vector<U>(s.elems);
}

template<typename U, size_t MaxSize>
Stack<U,MaxSize>& Stack<U,MaxSize>::operator=(const Stack& s){//注意这里的返回值类型需要加上 <U> 这里表示的类型
    return elems == s.elems;
}

template<typename U,size_t MaxSize>
void Stack<U,MaxSize>::push(const U& elem){
    this->elems.push_back(elem);
}

template<typename U,size_t MaxSize>
void Stack<U,MaxSize>::pop(){
    this->elems.pop_back();
}

template<typename U,size_t MaxSize>
U& Stack<U,MaxSize>::top() const{
    U elem = this->elems.back();
    this->elems.pop_back();
    return elem;
}

int main(){
    Stack<int,5> s1;
    Stack<float,10> s2;
    return 0;
}


