//Написать программу класса Комплексных чисел, которая выводит модуль комплексного числа, сложение, 
//вычитание, умножение и деление комплексных чисел.

#include <iostream>
#include <cmath>
using namespace std;

class complex 
{
public:
void vvod();
double modul();
void show_complex();
complex add (complex b);
complex sub(complex b);
complex mul(complex b);
complex div(complex b);
private:
double x;
double y;
};

void complex::vvod()
{
cout<<"Vvedite x: ";
cin>>x;
cout<<"Vvedite y: ";
cin>>y;
show_complex();
}
double complex::modul()
    {
    return pow(x*x+y*y,0.5);
    }

complex complex::add(complex b){
    complex res;
    res.x=x+b.x;
    res.y=y+b.y;
    return res;
}

complex complex::sub(complex b){
    complex res;
    res.x=x-b.x;
    res.y=y-b.y;
    return res;
}

complex complex::mul(complex b){
    complex res;
    res.x=x*b.x-y*b.y;
    res.y=x*b.y+y*b.x;
    return res;
}

complex complex::div(complex b){
    double denominator = b.x * b.x + b.y * b.y;
    if (denominator==0){
        throw invalid_argument("Division by zero in complex numbers is undefined.");
    }
    complex res;
    res.x = (x * b.x + y * b.y) / denominator;
    res.y = (y * b.x - x * b.y) / denominator;
    return res;
}

void complex::show_complex()
{
    if (y>=0) 
    cout<<x<<"+"<<y<<"i"<<endl;
    else cout<<x<<y<<"i"<<endl;
}
int main()
{
complex a;
complex b;
a.vvod();
b.vvod();
cout<<"Modul kompleksnogo chisla="<<a.modul()<<endl;
cout<<"Summa kompleksnogo chisla=";
a.add(b).show_complex();
cout<<"Raznost kompleksnogo chisla=";
a.sub(b).show_complex();
cout<<"Proizvedenie kompleksnogo chisla=";
a.mul(b).show_complex();
try{
    cout<<"Delenie kompleksnogo chisla=";
a.div(b).show_complex();
}catch (const exception& e) {
    cerr << "Error: " << e.what() << endl;
}
char r;
cin>>r;
    return 0;
}
