#include <iostream>
using namespace std;

void hanoi(int n,char f,char b,char t){//from,between,to
    if(n==1){
        cout<<f<<" "<<t<<endl;
    }
    else{
        hanoi(n-1,f,t,b);
        cout<<f<<" "<<t<<endl;
        hanoi(n-1,b,f,t);
    }
}

int main(){
    int n;
    cin>>n;

    hanoi(n,'A','B','C');

    return 0;
}