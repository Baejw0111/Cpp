//모든 정렬은 오름차순으로 이뤄진다.
#ifndef Sort_h
#define Sort_h

namespace sort{
    template <typename T>
    void swap(T *a,T *b){//두 인덱스의 값을 바꾸는 함수
        T tmp=*a;
        *a=*b;
        *b=tmp;
    }

    template <typename T>
    void bubble_sort(int n,T *a){//개선된 버블 정렬. n은 자료의 개수
        int s=1;//각 단계에서 데이터 이동이 이뤄지지 않을 시 함수 종료

        for(T *i=a+n-1;s;i--){//비교할 수의 개수를 하나씩 줄여나감
            s=0;
            for(T *j=a;j<i;j++){
                if(*j>*(j+1)){
                    swap(j,j+1);
                    s=1;
                }
            }
        }
    }

    template <typename T>
    void selection_sort(int n,T* a){//선택 정렬
    //가장 작은 값을 골라 맨 앞으로 옮긴다.
        for(int i=0;i<n;i++){
            int min=i;//가장 작은 값을 가진 인덱스
            for(int j=i;j<n;j++){
                if(*(a+j)<*(a+min)){
                    min=j;
                }
            }
            swap(a+i,a+min);
        }
    }

    template <typename T>
    void insertion_sort(int n,T *a){//삽입 정렬
    //뒤로 가면서 해당 원소를 순서에 맞는 자리에 삽입
        for(T *i=a+1;i<a+n;i++){
            for(T *j=i-1;j>=a&&*j>*(j+1);j--){
                swap(j,j+1);
            }
        }
    }

    template <typename T>
    void quick_sort(T *a,int left,int right){//퀵 정렬. left에 첫 인덱스, right에 데이터 크기를 넣으면 된다.
        T *pivot=a+left;
        int i=left,j=right;

        if(left<right){//해당 조건 불만족 시 재귀 종료
            do{
                do{
                    i++;
                }while(i<right && *(a+i)<*pivot);

                do{
                    j--;
                }while(*(a+j)>*pivot);

                if(i<j){
                    swap(a+i,a+j);
                }

            }while(i<j);
            swap(a+j,pivot);
            quick_sort(a,left,j);
            quick_sort(a,j+1,right);
        }
    }

    template <typename T>
    void heap_adjust(int n,T *a,int s){//힙 재조정. s는 노드 인덱스 값으로, 해당 노드가 내려가는 걸 계속 추적하며 반복한다.
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
            if(s==r){
                break;
            }
        }
    }

    template <typename T>
    void heap_sort(int n,T *a){
        for(int i=n/2;i>=0;i--){
            heap_adjust(n,a,i);
        }

        for(int i=n-1;i>0;i--){
            swap(a,a+i);
            heap_adjust(i,a,0);
        }
    }

    template <typename T>
    T* merge(T *L1,int a,T *L2,int b){
        int n=a+b;
        int x=0,y=0;//각 배열의 첫번째 원소의 인덱스를 가리킴
        T *L=new T[n];
        int s=0;//배열 L의 첫번째 원소의 인덱스를 가리킴

        //두 배열의 가장 앞 원소들을 비교해 작은 것부터 배열 L에 넣기
        while(a>0&&b>0){
            if(L1[x]>L2[y]){
                L[s++]=L2[y++];
                b--;
            }
            else{
                L[s++]=L1[x++];
                a--;
            }
        }

        //한쪽 배열이 비면 남은 배열의 원소들을 L에 넣기
        if(a==0){
            while(b>0){
                L[s++]=L2[y++];
                b--;
            }
        }
        else if(b==0){
            while(a>0){
                L[s++]=L1[x++];
                a--;
            }
        }

        return L;
    }

    template <typename T>
    T* merge_sort(int n,T* L){
        if(n>1){
            int m=n/2;
            T *L1=new int[m],*L2=new int[n-m];

            L1=L;
            L2=L+m;

            L=merge(merge_sort(m,L1),m,merge_sort(n-m,L2),n-m);
            //배열을 재귀적으로 쪼개며 정렬하기
        }
        return L;
    }
}

#endif