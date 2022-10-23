#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;

    int *a=new int[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=n-1;i>=0;i--){
        int tmp;
        cin>>tmp;
        a[i]+=tmp;
    }

    for(int i=0;i<n;i++){
        cout<<" "<<a[i];
    }

    delete a;

    return 0;
}