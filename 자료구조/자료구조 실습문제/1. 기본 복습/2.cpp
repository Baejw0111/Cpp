#include <iostream>
#include <string>
using namespace std;

void ABC(int *a,int k){
    int max=k;
    for(int i=k;i<10;i++){
        if(*(a+max)<*(a+i)){
            max=i;
        }
    }

    int tmp=*(a+k);
    *(a+k)=*(a+max);
    *(a+max)=tmp;
}

int main(){
    int a[10];
    for(int i=0;i<10;i++){
        cin>>a[i];
    }

    for(int i=0;i<10;i++){
        ABC(a,i);
    }

    for(int i=0;i<10;i++){
        cout<<" "<<a[i];
    }

    return 0;
}