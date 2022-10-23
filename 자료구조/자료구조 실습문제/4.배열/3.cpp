#include <iostream>
using namespace std;

int main(){
    int n;

    cin>>n;

    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=n*i+1;j<=n*(i+1);j++){
                cout<<" "<<j;
            }
            cout<<endl;
        }
        else{
            for(int j=n*(i+1);j>=n*i+1;j--){
                cout<<" "<<j;
            }
            cout<<endl;
        }
    }

    return 0;
}