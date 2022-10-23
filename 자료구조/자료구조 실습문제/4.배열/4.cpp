#include <iostream>
using namespace std;

int main(){
    int n,m,a[100][100];

    cin>>n>>m;

    int num=1;
    int row=0,col=0,r=0,c=1;

    while(num<=n*m){
        a[row][col]=num;
        if(r==0&&c==1){//>
            if(a[row][col+c]!=0||col+c==m){
                r=1;
                c=0;
            }
        }
        else if(r==1&&c==0){//v
            if(a[row+r][col]!=0||row+r==n){
                r=0;
                c=-1;
            }
        }
        else if(r==0&&c==-1){//<
            if(a[row][col+c]!=0||col+c<0){
                r=-1;
                c=0;
            }
        }
        else if(r==-1&&c==0){//<
            if(a[row+r][col]!=0||row+r<0){
                r=0;
                c=1;
            }
        }

        row+=r;
        col+=c;
        num++;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<" "<<a[i][j];
        }
        cout<<endl;
    }

    return 0;
}