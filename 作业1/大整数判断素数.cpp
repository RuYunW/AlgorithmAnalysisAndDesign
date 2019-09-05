/*
 * 大整数测试素数算法
 * 2019年9月5日
*/

#include<iostream>
#include<string>
#include<cstdio>
#include <cstring>
using namespace std;

int bigIntPrime(char* n, int m){
    int ans = 0;
    int len = strlen(n);
    for (int i = 0; i < len; i++)
//        ans = (int)((((long long)ans * 10) % m + (n[i] - '0') % m) % m);
        ans=(ans*10+n[i]-'0')%m;
    return ans;
}

bool primeJudger(char * n){
    for(int i=2;i*i<(long long)n;i++){
        if(bigIntPrime(n,i)==0){
            return false;
        }
    }
    return true;
}
int main(){
    char n[1024];
    cout<<"请输入欲判断素数的大整数（<=1024位）：";
    cin>>n;
    cout<<"数字"<<n;
    if(primeJudger(n)){
        cout<<"是素数";
    }else{
        cout<<"不是素数";
    }


    return 0;
}



