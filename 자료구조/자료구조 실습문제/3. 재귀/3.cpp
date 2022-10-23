#include <iostream>
using namespace std;

void seperate(int n){
    if(n==0){
        return;
    }
    cout<<n%10<<endl;
    seperate(n/10);    
}

int main(){
    int n;
    cin>>n;

    seperate(n);

    return 0;
}