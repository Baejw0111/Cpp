#include <iostream>
#include "CDLL.cpp"
using namespace std;
using namespace lst;


int main(){
    int n,k;
    cin>>n>>k;
    CDLL<int> list;

    list.Josephus(n,k);

    return 0;
}