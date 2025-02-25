//Напишите программу, которая выводит квадраты нечетных целых чисел от 1 до предела который вводит пользователь.
#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Введите количество чисел: ";
    cin>>n;
    for (int i=1; i<=n; i+=2){
        cout<<"Квадраты нечетных чисел: "<<i*i<<endl;
    }
    char r;
    cin>>r;
    return 0;
}