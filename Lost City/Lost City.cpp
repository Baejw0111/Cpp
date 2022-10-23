#include <iostream>
#include "OS.cpp"
using namespace std;

int main()
{
    cout << "==Welcome to Lost City!!==\n"
         << endl;
    system("pause");
    system("cls");

    OS Operator;

    while (!Operator.GameEnd())
    {
        Operator.Turn();
    }
    Operator.WinnerMessage();

    return 0;
}