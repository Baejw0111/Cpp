#include <iostream>
#include <string>
using namespace std;

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int main(){
    int n,arr[50];

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int a,b;

    cin>>a>>b;

    swap(arr+a,arr+b);

    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }

    return 0;
}