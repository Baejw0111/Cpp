#include <iostream>
using namespace std;

int main(){
    int n,m,a[100];
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cin>>m;

    int x,tmp;
    cin>>x;
    tmp=a[x];

    for(int i=1;i<m;i++){
        int y,tmp2;
        cin>>y;
        tmp2=a[y];
        a[y]=tmp;
        tmp=tmp2;
    }

    for(int i=0;i<n;i++){
        cout<<" "<<a[i];
    }

    return 0;
}