#include <iostream>

//난수 생성을 위해서는 다음 두 헤더를 포함해야 한다.
#include <cstdlib>
#include <ctime>

//실제 시간 측정을 위해서는 다음 헤더를 포함해야 한다.
#include <windows.h>
using namespace std;

void test(){
    int total=0;

    for(int i=0;i<10000;i++){
        total+=i;
    }

}

int main()
{
    //난수

    srand(time(NULL));//이렇게 하면 계속해서 난수 생성 가능
    cout<<rand()<<endl;

    //아래와 같이 하면 0 ~ 1,073,741,823 범위의 난수 생성이 가능하다.
    cout<<(((long) rand() << 15) | rand())<<endl;


    //시간 측정
    //아래 두 함수를 이용하면 clock() 함수와 달리 0.1us의 시간까지 측정한다.
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start,end,diff;

    QueryPerformanceFrequency(&ticksPerSec);//메인보드의 고해상도 타이머의 주파수를 얻는 함수
    //단, 두 함수 측정 시간 비교시 이 함수는 한번만 선언하면 된다.

    
    QueryPerformanceCounter(&start);//타이머의 CPU 클럭수를 얻는 함수
    // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
    test();
    QueryPerformanceCounter(&end);

    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("time: %.12f sec\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));
    //출력은 초 단위다.

    return 0;
}