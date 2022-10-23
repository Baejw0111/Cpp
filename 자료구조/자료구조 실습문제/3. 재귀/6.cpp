#include <iostream>
#include <cstring>
using namespace std;

int search(char a[],char b,int i){
    if(i==strlen(a)-1){
        return a[i]==b;
    }
    else{
        return (a[i]==b)+search(a,b,i+1);
    }
}

int main(){
    char a[100],b;

    cin>>a>>b;

    cout<<search(a,b,0)<<endl;

    return 0;
}