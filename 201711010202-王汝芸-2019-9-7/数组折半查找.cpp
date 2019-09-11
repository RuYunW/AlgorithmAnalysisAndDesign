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
int binarySearch(int *n,int key){
    int mid, low = 1, high = N;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == n[mid - 1]) return mid;//�ҵ���������ؽ��
        else if (key < n[mid - 1]) high = mid - 1;
        else low = mid + 1;
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
    print(binarySearch(n, key));  // ��ӡ���ҽ��,���rearch����Ϊ��ţ����ӡ��ţ�����0�������ʧ��
    return 0;
}