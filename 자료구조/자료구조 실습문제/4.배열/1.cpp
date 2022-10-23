#include <iostream>
using namespace std;

void swap(int *x,int *y){
    int tmp=*x;
    *x=*y;
    *y=tmp;
}

int main(){
    int n,m,a[100];
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;

        if((y-x)%2==0){
            for(int i=0;i<(y-x)/2+1;i++){
                swap(a+i+(x+y)/2,a-i+(x+y)/2);
            }
        }
        else{
            for(int i=0;i<(y-x)/2+1;i++){
                swap(a-i+(x+y)/2,a+i+1+(x+y)/2);
            }
        }

    }

    for(int i=0;i<n;i++){
        cout<<" "<<a[i];
    }

    return 0;
}