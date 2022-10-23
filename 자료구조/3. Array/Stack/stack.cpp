#include <iostream>
#include "StackArray.cpp"
using namespace std;
using namespace arr;

int main()
{
    int n;
    cin>>n;
    Stack<int> s(n);

    int sw=1;
    while(sw){
        int m,item;
        cout<<"choose mode(0:insert / 1:delete / 2: finish): ";
        cin>>m;

        switch (m)
        {
        case 0:
            cout<<"insert element: ";
            cin>>item;
            s.Push(item);
            break;
        
        case 1:
            s.Pop();
            break;
        
        case 2:
            sw=0;
            break;
        }

        s.Print();
        cout<<endl;
    }

    return 0;
}