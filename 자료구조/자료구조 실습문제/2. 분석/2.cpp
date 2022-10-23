#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int mostOnesSlowVersion(int **a,int n){
    int imax,jmax=0;

    for(int i=0;i<n;i++){
        int j=0;
        while(j<n&&a[i][j]==1){
            j++;
        }

        if(j>jmax){
            jmax=j;
            imax=i;
        }
    }

    return imax;
}

int mostOnesFastVersion(int **a,int n){
    int imax,jmax=0;

    for(int i=0;i<n;i++){
        int j=jmax;
        while(j<n&&a[i][j]==1){
            j++;
        }

        if(j>jmax){
            jmax=j;
            imax=i;
        }
    }

    return imax;
}

int main()
{
    int n,**a,ans;
    cin>>n;

    a=new int*[n];
    for(int i=0;i<n;i++){
        a[i]=new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start,end,diff;

    QueryPerformanceFrequency(&ticksPerSec);

    QueryPerformanceCounter(&start);
    mostOnesSlowVersion(a,n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("Slow Version time: %.12f sec\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));

    QueryPerformanceCounter(&start);
    ans=mostOnesFastVersion(a,n);
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("Fast Version time: %.12f sec\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));

    cout<<ans;

    delete[] a;
    return 0;
}