#include <iostream>
#include <cstring>
using namespace std;

void shift(char *a){
    char tmp=*a;
    for(char *i=a;i<a+strlen(a)-1;i++){
        *i=*(i+1);
    }
    *(a+strlen(a)-1)=tmp;
}

int main(){
    char a[100];
    scanf("%s",a);

    for(int i=0;i<strlen(a);i++){
        printf("%s\n",a);
        shift(a);
    }

    return 0;
}