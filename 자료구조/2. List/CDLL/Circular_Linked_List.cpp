#include <iostream>
#include "CDLL.cpp"
using namespace std;
using namespace lst;


int main(){
    int s=0,m,n;
    CDLL<int> list;

    while(s==0){
        printf("\n===MENU===\n");
        printf("1: 데이터 삽입\n");
        printf("2: 데이터 삭제\n");
        printf("3: 거꾸로 출력\n");
        printf("4: 프로그램 끝내기\n");

        printf("선택할 메뉴 입력: ");
        cin>>m;

        switch (m)
        {
            case 1:
                cin>>n;
                list.Add(n);
                break;
                
            case 2:
                cin>>n;
                list.Delete(n);
                break;

            case 3:
                list.Reverse();
                break;

            case 4:
                s++;
                break;
        }

        list.Print();
    }
    return 0;
}