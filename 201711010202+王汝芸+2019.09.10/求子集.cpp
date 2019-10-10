#include <stdlib.h>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

static void OutputOneSubsetBinary();
static void OutputOneSubset();

static vector<int> x;
void subsetting(int n)
{
    if (n > 0) {
        x.push_back(0);
        subsetting(n - 1);
        x.pop_back();
        x.push_back(1);
        subsetting(n - 1);
        x.pop_back();
    }
    else {
        OutputOneSubsetBinary();
        OutputOneSubset();
        printf("\n");
    }
}


int main(){
    int n = 17;
    clock_t startTime,endTime;
    startTime = clock();//计时开始
    subsetting(n);
    endTime = clock();//计时结束
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}


static void OutputOneSubsetBinary() {
    static int cnt = 0;
    printf("%03d: ", ++cnt);
    for (int i = x.size() - 1; i >= 0; i--)
        printf("%d", x[i]);
}

static void OutputOneSubset() {
    printf("; {");
    int k = 0;
    for (int i = x.size() - 1; i >=0; i--) {
        if (x[i] == 1) {
            if (k > 0)
                printf(",");
            printf("%d", x.size() - i);
            k++;
        }
    }
    printf("}");
}
