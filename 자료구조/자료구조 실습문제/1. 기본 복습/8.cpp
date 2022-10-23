#include <iostream>
#include <string>
using namespace std;

typedef struct{
    string name;
    int score[3];
    double avg;
}stu;

int main(){
    int n;

    cin>>n;

    stu *a=new stu[n];

    for(stu *i=a;i<a+n;i++){
        cin>>i->name;
        for(int j=0;j<3;j++){
            cin>>i->score[j];
            i->avg+=i->score[j];
        }
        i->avg/=3;
    }

    for(stu *i=a;i<a+n;i++){
        int g=0,b=0;
        cout<<fixed;
        cout.precision(1);
        cout<<i->name<<" "<<i->avg;

        for(int j=0;j<3;j++){
            if(g*b){
                break;
            }

            if(i->score[j]>=90){
                g=1;
            }
            else if(i->score[j]<70){
                b=1;
            }
        }

        if(g){
            cout<<" GREAT";
        }
        if(b){
            cout<<" BAD";
        }

        cout<<endl;
    }


    delete[] a;

    return 0;
}