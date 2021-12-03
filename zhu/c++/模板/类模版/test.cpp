#include <iostream>
#include <vector>
using namespace std;

int max = 0;
vector<int> timer;
int m = 0,n = 0;

void helper(int index, bool flag, int upper, int sum){
    if(index == timer.size()){
        if(sum > max) max = sum;
        return;
    }
    
    if(timer[index] < upper){//表明当前不可选
        helper(index+1,false,upper,sum);
    }else{//标明当前可选 有两种情况 选还是不选
        helper(index+1,true,upper+m,sum+1);
        helper(index+1,false,upper,sum);
    }

}

int main(){
    cin>>n>>m;
    
    for(int i = 0; i < n; i++){
        int t1,t2;
        cin>>t1>>t2;
        timer.push_back(t1+t2);
    }

    helper(1,true,m,1);
    helper(1,false,m,0);

    cout<<sum<<endl;

}