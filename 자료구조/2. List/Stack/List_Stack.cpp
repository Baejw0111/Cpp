#include <iostream>
#include "StackList.cpp"
using namespace std;
using namespace lst;


int main(){
    int s=0,m,n;
    Stack<int> list;

    while(s==0){
        printf("\n===MENU===\n");
        printf("1: 데이터 삽입\n");
        printf("2: 데이터 삭제\n");
        printf("3: Top 값 출력\n");
        printf("4: 프로그램 끝내기\n");

        printf("선택할 메뉴 입력: ");
        cin>>m;

        switch (m)
        {
            case 1:
                cin>>n;
                list.Push(n);
                break;
                
            case 2:
                if(list.isEmpty()){
                    cout<<"Stack is empty!"<<endl;
                }
                else{
                    cout<<list.Pop()<<endl;
                }
                break;

            case 3:
                cout<<"Top: "<<list.Top()<<endl;
                break;

            case 4:
                s++;
                break;
        }

        list.DLL::Print();
    }
    return 0;
}