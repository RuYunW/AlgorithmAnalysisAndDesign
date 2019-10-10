#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<algorithm>
#define N 100
using namespace std;

int* createRandArray(int *n){
    srand((int)time(0));  // 产生随机种子  把0换成NULL也行
    for (int i = 0; i < N; i++){
        n[i] = rand()%100;
    }
    return n;
}

int* sortArray(int *n){
    sort(n,n+N);
    return n;
}

//查找函数
int binarySearch(int *n,const int key,const int left,const int right){
    int mid, low = left, high = right;
    if (low <= high)
    {
        mid = (low + high) / 2;

        if (key < n[mid - 1]){
            return binarySearch(n,key,low,mid-1);
        }
        else if (key>n[mid-1]){
            return binarySearch(n,key,mid+1,high);
        }
        else{
            return mid;
        }
    }
    return 0;
}

//打印结果函数
void print(int result)
{
    if (result) printf("\n查找的数字是第%d个\n\n", result);
    else printf("查找失败\n\n");
}

int main()
{
    int n[N];
    int key;  // 关键值
    createRandArray(n);
    cout<<"随机生成长度为"<<N<<"的数组"<<endl;
    sortArray(n);
    cout<<"数组排序完毕"<<endl;
    cout<<"请输入关键字key的值：";
    cin>>key;
    for(int i = 0;i<N;i++){
        cout<<n[i]<<" ";
    }
    print(binarySearch(n, key,1,N));  // 打印查找结果,如果rearch返回为序号，则打印序号，返回0，则查找失败
    return 0;
}