//Напишите программу, которая предлагает ввести два целых числа,
// а затем использует конструкцию if-else для вывода сообщения о том, равны ли два числа.

#include <iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter the number a: ";
    cin>>a;
    cout<<"Enter the number b: ";
    cin>>b;
    if (a=b){
        cout<<"The numbers are equal";
    }
    else{
        cout<<"The numbers are not equal";
    }
    char r;
    cin>>r;
    return 0;
}