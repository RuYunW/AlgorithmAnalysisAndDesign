/*
 * ?????????
 * 2019?9?5?
*/

#include<iostream>
#include<string>
#include<cstdio>
#include <ctime>
#include <cstring>
# define N 2014
using namespace std;

void createRandArray(char *n){
    srand((int)time(0));
    for (int i = 0; i < N; i++){
        n[i] = (int)(rand()%100)/10+'0';
    }
}

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
    char n[N];

    createRandArray(n);
//    cout<<n[0];

    cout<<"create rand big int number "<<endl;
    for(int i = 0;i<N;i++){
        cout<<n[i];
    }

    if(primeJudger(n)){
        cout<<"\nis prime";
    }else{
        cout<<"\nis not prime";
    }
    return 0;
}
