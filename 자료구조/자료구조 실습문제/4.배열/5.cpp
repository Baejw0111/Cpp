#include <iostream>
using namespace std;

int main(){
    int n,m,a[100][100];

    cin>>n>>m;

    int num=1;
    int row=0,col=0;

    while(row<n){
        for(int i=row,j=col;i<n&&j>=0;i++,j--,num++){
            a[i][j]=num;
        }
        if(col<m-1){
            col++;
        }
        else{
            row++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<" "<<a[i][j];
        }
        cout<<endl;
    }

    return 0;
}