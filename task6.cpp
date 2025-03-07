//Написать программу класса Рациональных чисел, которая выводит сложение, 
//вычитание, умножение и деление рациональных чисел и сокращение дроби.

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
class rational{
    public:
        rational(): numerator(0), denominator(1) {};
        rational(int num, int denom) : numerator(num), denominator(denom) {
            norm();
        };
        rational input_rational();
        rational add(const rational& b);
        rational sub(const rational& b);
        rational mul(const rational& b);
        rational div(const rational& b);
        void norm();
        int gcd(int a, int b); //Вычисление НОД по алгоритму Евклида
        void show_rational();
    private:
    int numerator;
    int denominator;
};

// Метод для нормализации дроби
void rational::norm() {
    int commonDivisor = gcd(abs(numerator), abs(denominator));
    numerator /= commonDivisor;
    denominator /= commonDivisor;

    // Убедимся, что знаменатель положительный
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Ручная реализация GCD (алгоритм Евклида)
int rational ::  gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

rational rational:: input_rational(){
    cout<<"Vvedite numerator: ";
    cin>>numerator;
    cout<<"Vvedite denominator: ";
    cin>>denominator;
    return rational(numerator, denominator);
}

rational rational:: add(const rational& b){
    int newNumerator = numerator * b.denominator + b.numerator * denominator;
    int newDenominator = denominator * b.denominator;
    return rational(newNumerator, newDenominator);
}

rational rational:: sub(const rational& b){
    int newNumerator = numerator * b.denominator - b.numerator * denominator;
    int newDenominator = denominator * b.denominator;
    return rational(newNumerator, newDenominator);
}

rational rational:: mul(const rational& b){
    int newNumerator = numerator * b.numerator;
    int newDenominator = denominator * b.denominator;
    return rational(newNumerator, newDenominator);
}
rational rational:: div(const rational& b){

    int newNumerator = numerator * b.denominator;
    int newDenominator = denominator * b.numerator;
    return rational(newNumerator, newDenominator);
}
void rational::show_rational(){
        if (denominator==1){
            cout<<numerator<<endl;
     }
        else{
            cout<<numerator<<"/"<<denominator<<endl;
        }
}

int main(){
    rational a (1,2);
    rational b (1,4);
    a.show_rational();
    b.show_rational();
    cout<<"Summa rational chisel ravno: "<<endl;
    a.add(b).show_rational();
    cout<<"Raznost rational chisel ravno: "<<endl;
    a.sub(b).show_rational();
    cout<<"Proizvedenie rational chisel ravno: "<<endl;
    a.mul(b).show_rational();
    cout<<"Delenie rational chisel ravno: "<<endl;
    a.div(b).show_rational();
    char r;
    cin>>r;
    return 0;
}