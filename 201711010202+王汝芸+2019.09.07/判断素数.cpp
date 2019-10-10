/*
 * 测试素数的试除算法
 * 2019年9月4日
*/
#include <iostream>
using namespace std;

//素数判断函数，如果是素数返回True
bool PrimeNumJudger(int num){
    for(int i = 2;i*i<=num;i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    cout<<"请输入欲判断素数的整数：";
    cin>>num;
    cout<<"数字"<<num;
    if(PrimeNumJudger(num)){
        cout<<"是"<<endl;
    }else{
        cout<<"不是"<<endl;
    }
    cout<<"素数";
    return 0;
}
