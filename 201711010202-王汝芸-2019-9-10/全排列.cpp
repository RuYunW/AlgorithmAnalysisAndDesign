#include <vector>
#include <utility>
#include <iostream>
#include <ctime>
using namespace std;
static void Permuting(int i);
static void OutputOnePermutation();
void PermutingCaller(int n);
static vector<int> x;
static int N;

int main(){
    int n = 9;
    clock_t startTime,endTime;
    startTime = clock();//计时开始

    PermutingCaller(n);
    endTime = clock();//计时结束

    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
void PermutingCaller(int n)
{
    N = n;
    for (int i = 0; i < n; ++i)
        x.push_back(i + 1);
    Permuting(0);
}
static void Permuting(int i)
{
    if (i < N - 1) {
        for (int j = i; j < N; ++j) {
            swap(x[i], x[j]);
            Permuting(i + 1);
            swap(x[i], x[j]);
        }
    }
    else
        OutputOnePermutation();
}
static void OutputOnePermutation()
{
    static int cnt = 0;
    printf("%03d: ", ++cnt);
    for (auto x : x)
        printf("%d", x);
    printf("\n");
}
