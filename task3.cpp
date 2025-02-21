//Напишите программу, которая предлагает ввести два целых числа и выясняет, 
//делится ли первое число на второе без остатка (кратно ли второе число). 
//Предусмотрите вариант, когда в качестве второго числа можно ввести 0 (на ноль делить нельзя). 
//В этом случае программа ничего не вычисляет, а просто завершает выполнение.

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a,b;
    cout<<"Enter the number a: ";
    cin>>a;
    cout<<"Enter the number b: ";
    cin>>b;
    if (b!=0){
        if (a%b==0){
            cout<<"The number a is divisible by b without remainder. ";
        }
        else{
            cout<<"The number a is not divisible by b without remainder";
        }
    }
    else{
        cout<<"Numbers are not divisible by zero!!!";
    }
    char r;
    cin>>r;
    return 0;
}