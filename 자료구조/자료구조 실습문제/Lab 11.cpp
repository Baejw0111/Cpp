#include <iostream>
using namespace std;

class HashTable{
struct infor{
    int n;
};
infor *table;
int hash,eleNum;//'eleNum' is current number of emements in hash table

public:
    HashTable(int n);
    void Insert(int n);
    void Delete(int n);
    void Print();
    ~HashTable();
};

int main(){
    int s = 1, n; //'s' is for loop control. 'n' is for input.
    char m;       //'m' is for mode.

    cin>>n;
    HashTable H(n);

    while(s){
        cin>>m;

        switch (m)
        {
            case 'i':
                cin>>n;
                H.Insert(n);
                break;
                
            case 'p':
                H.Print();
                break;

            case 'r':
                cin>>n;
                H.Delete(n);
                break;

            case 'x':
                s=0;
                break;
        }

    }


    return 0;
}

HashTable::HashTable(int n){
    table=new infor[n];
    eleNum=0;
    hash=n;

    for(int i=0;i<n;i++){
        (table+i)->n=0;
    }
}

void HashTable::Insert(int n){
    if(eleNum==hash){
        cout<<"Hash table is full"<<endl;
    }
    else{
        infor *start=table+n%hash;
        if(start->n==n){
            return;
        }
        else if(start->n<=0){
            start->n=n;
        }
        else{
            while(start->n>0){
                if(start==(table+hash-1)){
                    start=table;
                }
                else{
                    start++;
                }
            }
            start->n=n;
        }
        eleNum++;
    }
}

void HashTable::Delete(int n){
    for(int i=0;i<hash;i++){
        if((table+i)->n==n){
            (table+i)->n=-1;
            eleNum-=1;
            return;
        }
    }
}

void HashTable::Print(){
    for(int i=0;i<hash;i++){
        if((table+i)->n>0){
            cout<<(table+i)->n<<" at "<<i<<endl;
        }
    }
}

HashTable::~HashTable(){
    delete[] table;
}