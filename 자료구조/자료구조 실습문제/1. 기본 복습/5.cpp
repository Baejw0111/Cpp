#include <iostream>
#include <string>
using namespace std;

typedef struct{
    int h,m,s;
}t;

int main(){
    t a,b;

    cin>>a.h>>a.m>>a.s;
    cin>>b.h>>b.m>>b.s;

    b.h-=a.h;
    b.m-=a.m;
    b.s-=a.s;

    if(b.s<0){
        b.s+=60;
        b.m-=1;
    }
    if(b.m<0){
        b.m+=60;
        b.h-=1;
    }

    cout<<b.h<<" "<<b.m<<" "<<b.s;

    return 0;
}