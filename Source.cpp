//
// Created by Pablo Chávez on 21/06/26.
//
#include <iostream>
using namespace std;

//declaring function welcome
void welcome()
{
    cout << "Welcome to the C++ Programming Language" << endl;
}
void printNumber(int num)
{
    cout << num << endl;
}
int add(int a, int b)
{
    int result = a + b;
    return result;
}

int main()
{
    //welcome function
    welcome();
    printNumber(add(5, 3));

}
