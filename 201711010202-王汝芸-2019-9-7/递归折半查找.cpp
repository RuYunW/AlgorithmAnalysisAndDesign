#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdio>
#include<algorithm>
#define N 100
using namespace std;

int* createRandArray(int *n){
    srand((int)time(0));  // �����������  ��0����NULLҲ��
    for (int i = 0; i < N; i++){
        n[i] = rand()%100;
    }
    return n;
}

int* sortArray(int *n){
    sort(n,n+N);
    return n;
}

//���Һ���
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

//��ӡ�������
void print(int result)
{
    if (result) printf("\n���ҵ������ǵ�%d��\n\n", result);
    else printf("����ʧ��\n\n");
}

int main()
{
    int n[N];
    int key;  // �ؼ�ֵ
    createRandArray(n);
    cout<<"������ɳ���Ϊ"<<N<<"������"<<endl;
    sortArray(n);
    cout<<"�����������"<<endl;
    cout<<"������ؼ���key��ֵ��";
    cin>>key;
    for(int i = 0;i<N;i++){
        cout<<n[i]<<" ";
    }
    print(binarySearch(n, key,1,N));  // ��ӡ���ҽ��,���rearch����Ϊ��ţ����ӡ��ţ�����0�������ʧ��
    return 0;
}