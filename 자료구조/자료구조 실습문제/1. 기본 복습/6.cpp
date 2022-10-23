#include <iostream>
#include <string>
using namespace std;

typedef struct{
    string name;
    int score;
}stu;

int main(){
    stu a[5];
    double avg=0;

    for(int i=0;i<5;i++){
        cin>>a[i].name>>a[i].score;
        avg+=a[i].score;
    }

    avg/=5;

    for(int i=0;i<5;i++){
        if(a[i].score<=avg){
            cout<<a[i].name<<endl;
        }
    }

    return 0;
}