#include <iostream>
#include "QueueArray.cpp"
using namespace std;
using namespace arr;

int main()
{
    int n;
    cin>>n;
    Cqueue<int> q(n);

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
            q.Insert(item);
            break;
        
        case 1:
            q.Delete();
            break;
        
        case 2:
            sw=0;
            break;
        }

        q.Print();
        cout<<endl;
    }

    return 0;
}