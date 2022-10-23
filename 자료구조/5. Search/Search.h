#ifndef Search_h
#define Search_h

template <typename T>
int sequential_search(int size,T n,T *a){//선형 검색 함수.size는 받은 배열 a의 크기, n은 찾는 수
    for(int i=0;i<size;i++){
        if(a[i]==n){
            return i;
        }
    }
}

template <typename T>
int binary_search(T n,T *a,int length){//이진 탐색 함수. n이 찾는 수이다. length는 배열의 길이다.
    int mid,start=0,end=length-1;
    //배열 길이가 0일 때 end가 length값과 같을 경우 쓰레기 값을 읽을 수 있다.

    while(start<=end){//비교 연산자가 '!='이면 무한 루프가 발생할 수 있다. start==end가 되는 부분을 건너뛰고 end<start가 되는 상황이 발생 가능하기 때문
        mid=(end+start)/2;
        if(a[mid]>n){
            end=mid-1;
        }
        else if(a[mid]<n){
            start=mid+1;
        }
        else{
            return mid;
        }

    }

    return -1;//찾지 못할 경우 -1 반환
}

#endif