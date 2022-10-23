#include <iostream>
using namespace std;

void seperate(int n){
    if(n==0){
        return;
    }
    seperate(n/10);    
    cout<<n%10<<endl;
}

int main(){
    int n;
    cin>>n;

    seperate(n);

    return 0;
}