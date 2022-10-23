#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int modulo(int a,int b){
    while(1){
        if(a-b<0){
            break;
        }
        else{
            a-=b;
        }
    }

    return a;
}
int main()
{
    int a,b;
    cin>>a>>b;    

    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start,end,diff;

    QueryPerformanceFrequency(&ticksPerSec);

    QueryPerformanceCounter(&start);
    a/b;
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("\n%% time: %.12f sec\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));

    QueryPerformanceCounter(&start);
    modulo(a,b);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("modulo time: %.12f sec\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));

    cout<<"ans: "<<modulo(a,b);

    return 0;
}