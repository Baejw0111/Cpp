#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int* prefixAverages1(int *a,int n){
    int *b;
    b=new int[n];

    for(int i=0;i<n;i++){
        double sum=0;
        for(int j=0;j<=i;j++){
            sum+=a[j];
        }
        sum/=i+1;
        b[i]=sum+0.5;
    }

    return b;
}

int* prefixAverages2(int *a,int n){
    int *b;
    double sum=0;
    b=new int[n];

    for(int i=0;i<n;i++){
        sum+=a[i];
        b[i]=sum/(i+1)+0.5;
    }

    return b;
}

int main()
{
    int n,*a;
    cin>>n;

    a=new int[n];

    srand(time(NULL));

    for(int i=0;i<n;i++){
        a[i]=rand()%10000+1;
    }

    int *b,*c;

    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start,end,diff;

    QueryPerformanceFrequency(&ticksPerSec);

    QueryPerformanceCounter(&start);
    b=prefixAverages1(a,n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("Slow Version time: %.12f sec\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));

    QueryPerformanceCounter(&start);
    c=prefixAverages2(a,n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("Fast Version time: %.12f sec\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}