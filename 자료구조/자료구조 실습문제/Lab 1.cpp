#include <iostream>
#include <string>
using namespace std;

int Menu();
void swap(string*,string*);//swap elements' position
void bubble_sort(int,string*);

class employee{
    private:
        string *emp=NULL;
        //string pointer of employee list;
        int current=0;
        //number of current employees in list

    public:
        employee();//allocate space to emp
        void Print();//print full list of employees
        void Insert();//insert new employee
        void Remove();//remove employee from list
        ~employee();//deallocate emp
};

int main(){
    employee e;
    int s=1;
    //'s' is switch for loop 

    while(s==1){
        switch(Menu()){
            case 0:
                s=0;
                break;

            case 1:
                e.Print();
                break;

            case 2:
                e.Insert();
                break;

            case 3:
                e.Remove();
                break;
        }
    }

    return 0;
}

employee::employee(){
    int n;
    //'n'is the expectation number of employees

    cout<<"How many employees do you expect to have ?"<<endl;
    cin>>n;
    cout<<endl;

    this->emp=new string[n];

}

int Menu(){//print menu
    int n;

    cout<<"Menu :"<<endl;
    cout<<"1 . Print full list of employees"<<endl;
    cout<<"2 . Insert new employee"<<endl;
    cout<<"3 . Remove employee from list"<<endl;
    cout<<"0 . Exit"<<endl;

    cin>>n;

    return n;//return menu number
}

void swap(string *a,string *b){
    string tmp=*a;
    *a=*b;
    *b=tmp;
}

void bubble_sort(int n,string *a){
    //'a' is string pointer of string array
    //'n' is number of element in array 'a'
    int s=1;
    //Stop when there is no more data movement(s=0).

    for(string *i=a+n-1;s;i--){
        s=0;
        for(string *j=a;j<i;j++){
            if((*j).compare(*(j+1))>0){
                swap(j,j+1);
                s=1;
            }
        }
    }
}

void employee::Print(){
    cout<<"List of current employees:"<<endl;
    int& size=this->current;

    for(int i=0;i<size;i++){
        cout<<i+1<<" . "<<this->emp[i]<<endl;
    }

    return;
}

void employee::Insert(){
    cout<<"Input name of new employee : ";

    int& size=this->current;
    cin>>this->emp[size];

    size+=1;//Increase the number of current employees.

    bubble_sort(size,this->emp);

    return;
}

void employee::Remove(){
    string tmp;
    string*& a=this->emp;

    cout<<"Enter name of employee to remove: ";
    cin>>tmp;

    int& size=this->current;
    for(string *i=a;i<a+size;i++){
        if(!(*i).compare(tmp)){
            for(string *j=i;j<i+size-1;j++){
                //Moves forward the positions of elements
                //located after the element to be deleted.
                swap(j,j+1);
            }
        }
    }

    size-=1;//Decrease the number of current employees.
}

employee::~employee(){
    delete[] this->emp;
}