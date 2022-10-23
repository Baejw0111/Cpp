#include <iostream>
using namespace std;

int max(int a[],int n){
    if(n==0){
        return a[0];
    }

    else if(max(a,n-1)<a[n]){
        return a[n];
    }
    else{
        return max(a,n-1);
    }
}

int main(){
    int a[20],n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<max(a,n-1)<<endl;

    return 0;
}