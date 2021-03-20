#include <stdio.h>

int var1 = 1;
int var2;

void func(int i){
    printf("%d\n",i);
}

extern char etext[];

int main(){
    static int var3 = 2;
    static int var4;
    func(var1 + var2 + var3 + var4);
    printf("%s",etext);
    return 0;
}