#include <iostream>
using namespace std;

int* array_init(int n){//make integer array
    int *a=NULL;
    a=new int[n];

    return a;
}

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void heap_adjust(int n,int *a,int s){//s is node index, this function track s decreasing
    while(s<n){
        int r=s;
        int left=2*s+1,right=2*s+2;
        if(left>=n&&right>=n){
            break;
        }

        if(right<n){
            if(*(a+left)>*(a+right)){
                if(*(a+left)>*(a+s)){
                    swap(a+s,a+left);
                    s=left;
                }
            }
            else{
                if(*(a+right)>*(a+s)){
                    swap(a+s,a+right);
                    s=right;
                }

            }
        }
        else{
            if(*(a+left)>*(a+s)){
                swap(a+s,a+left);
                s=left;
            }
        }
        if(s==r){//if s doesn't change
            break;
        }
    }
}

void heap_sort(int n,int *a){
    for(int i=n/2;i>=0;i--){
        heap_adjust(n,a,i);
    }

    // for(int i=n-1;i>0;i--){
    //     swap(a,a+i);
    //     heap_adjust(i,a,0);
    // }
    //if you want Min heap
}

int removeMax(int *a,int n){
    int tmp=*a;
    swap(a,a+n-1);

    return tmp;
}

int main(){
    int s = 1, n; //'s' is for loop control. 'n' is for input.
    char m;       //'m' is for mode.

    cin>>n;
    int *a=array_init(n);
    int length=0;//length is current length of array

    while(s){
        cin>>m;

        switch (m)
        {
            case 'i':
                cin>>n;
                *(a+length)=n;
                length++;
                heap_sort(length,a);
                break;
                
            case 'p':
                for(int i=0;i<length;i++){
                    cout<<*(a+i)<<" ";
                }
                cout<<endl;
                break;

            case 'r':
                cout<<removeMax(a,length)<<endl;
                length--;
                heap_sort(length,a);
                break;

            case 'x':
                s=0;
                break;
        }

    }

    delete[] a;

    return 0;
}
