#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};
typedef node* node_ptr;

class Tree{ //Binary Tree

public:
    node_ptr root;
    Tree();
    node_ptr Insert(node_ptr nod,int n);
    void PreOrder(node_ptr nod);
    void InOrder(node_ptr nod);
    void PostOrder(node_ptr nod);
    void FreeNode(node_ptr nod);
    ~Tree();
};

int main(){
    int s = 1, n; //'s' is for loop control. 'n' is for input.
    char m;       //'m' is for mode.
    Tree t;

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

            case 'x':
                s=0;
                break;
        }

    }
    return 0;
}

Tree::Tree():root(NULL){}

node_ptr Tree::Insert(node_ptr nod,int n){
    if(nod==NULL){
        node_ptr tmp=new node;
        tmp->data=n;
        tmp->left=NULL;
        tmp->right=NULL;

        return tmp;
    } 

    if(n<nod->data){
        nod->left=Insert(nod->left,n);
    }
    else{
        nod->right=Insert(nod->right,n);
    }
    return nod;
}

void Tree::PreOrder(node_ptr nod){
    if(nod!=NULL){
        cout<<nod->data<<" ";
        PreOrder(nod->left);
        PreOrder(nod->right);
    }
}

void Tree::InOrder(node_ptr nod){
    if(nod!=NULL){
        InOrder(nod->left);
        cout<<nod->data<<" ";
        InOrder(nod->right);
    }
}

void Tree::PostOrder(node_ptr nod){
    if(nod!=NULL){
        PostOrder(nod->left);
        PostOrder(nod->right);
        cout<<nod->data<<" ";
    }
}

void Tree::FreeNode(node_ptr nod){
    if(nod!=NULL){
        FreeNode(nod->left);
        FreeNode(nod->right);
        delete nod;
    }
}

Tree::~Tree(){
    FreeNode(root);
}