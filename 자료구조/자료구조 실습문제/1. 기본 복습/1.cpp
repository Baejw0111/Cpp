#include <iostream>
#include <string>
using namespace std;

int sum(int x){
    int total=0;
    for(int i=1;i<=x;i++){
        total+=i;
    }

    return total;
}

int main(){
    int x,total=0;
    cin>>x;

    for(int i=1;i<=x;i++){
        total+=sum(i);
    }

    cout<<total;

    return 0;
}