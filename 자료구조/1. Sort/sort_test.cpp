#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Sort.h"
using namespace std;

#define MAX 100

int main(){
    srand(time(NULL));
    int *a=new int[MAX];

    for(int i=0;i<MAX;i++){
        a[i]=rand();
    }

    for(int i=0;i<MAX;i++){
        cout<<a[i]<<endl;
    }
    cout<<endl;

    a=sort::merge_sort<int>(MAX,a);

    for(int i=0;i<MAX;i++){
        cout<<a[i]<<endl;
    }
}