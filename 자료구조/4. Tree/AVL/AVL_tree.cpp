#include <iostream>
#include "AVL.cpp"
using namespace std;
using namespace tree;

int main(){
    int s = 1, n; //'s' is for loop control. 'n' is for input.
    char m;       //'m' is for mode.
    AVL<int> t;

    while(s){
        cin>>m;

        switch (m)
        {
            case 'i':
                cin>>n;
                t.root=t.Insert(t.root,n);
                break;
                
            case 'p':
                t.PreOrder(t.root);
                break;

            case 'n':
                t.InOrder(t.root);
                break;
            
            case 'o':
                t.PostOrder(t.root);
                break;

            case 'l':
                t.LevelOrder(t.root);
                break;

            case 's':
                cin>>n;
                t.Search(t.root,n);
                break;

            case 'd':
                cin >> n;
                t.root = t.Delete(t.root, n);
                break;

            case 'x':
                s=0;
                break;
        }

    }
    return 0;
}