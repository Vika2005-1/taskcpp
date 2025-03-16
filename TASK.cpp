//Написать программу класса Рациональных чисел, которая выводит сложение, 
//вычитание, умножение и деление рациональных чисел и сокращение дроби. + Создать матрицу с 
//рациональными числами и их операциями над ними..

#include <iostream>
#include <cmath>
using namespace std;
class rational{
    public:
        rational();
        rational(int num, int denom=1);
        rational input_rational();
        rational add(rational b);
        rational sub(rational b);
        rational mul(rational b);
        rational div(rational b);
        void norm();
        void show_rational();
    private:
    int numerator;
    int denominator;
    int gcd(int A, int B);
};

rational::rational(){
    cout<<"Vvedite numerator: "<<endl;
    cin>>numerator;
    cout<<"Vvedite denominator "<<endl;
    cin>>denominator;
}

rational::rational(int num, int denom){
    numerator=num;
    denominator=denom;
}

int rational ::  gcd(int A, int B) {
    while (B != 0) {
        int temp = B;
        B = A % B;
        A = temp;
    }
    return A;
}

void rational::norm() {
    int C = gcd(abs(numerator), abs(denominator));
    numerator /= C;
    denominator /= C;
}

rational rational:: add(rational b) {
    rational res(0,0);
    res.numerator = numerator * b.denominator + b.numerator * denominator;
    res.denominator = denominator * b.denominator;
    return res;
}

rational rational:: sub(rational b) {
    rational res(0,0);
    res.numerator = numerator * b.denominator - b.numerator * denominator;
    res.denominator = denominator * b.denominator;
    return res;
}

rational rational:: mul(rational b) {
    rational res(0,0);
    res.numerator = numerator * b.numerator;
    res.denominator = denominator * b.denominator;
    return res;
}

rational rational:: div(rational b) {
    rational res(0,0);
    res.numerator = numerator * b.denominator;
    res.denominator = denominator * b.numerator;
    return res;
}

void rational::show_rational(){
    if (denominator==1){
        cout<<numerator;
 }
    else{
        cout<<numerator<<"/"<<denominator;
    }
}

class Matrix{
    public:
        Matrix(int rows, int cols);
        ~Matrix();
        Matrix add(Matrix b);
        Matrix sub(Matrix b);
        Matrix mul(Matrix b);
        Matrix div(Matrix b);
        void input();
        void show_matrix();
    private:
        int rows;
        int cols;
        rational** matrix;

};

Matrix::Matrix(int rows, int cols): rows(rows), cols(cols){
    matrix = new rational*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new rational[cols];
    }
}
Matrix::~Matrix(){
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::input() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int num, denom;
            cout << "Vvedite numerator i denominator elementa [" << i << "][" << j << "]: ";
            cin >> num >> denom;
            matrix[i][j] = rational(num, denom);
        }
    }
}

void Matrix::show_matrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j].show_rational();
            cout << " ";
        }
        cout << endl;
    }
}

Matrix Matrix::add(Matrix b) {
    Matrix res(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res.matrix[i][j] = matrix[i][j].add(b.matrix[i][j]);
        }
    }
    return res;
}

Matrix Matrix::sub(Matrix b) {
    Matrix res(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res.matrix[i][j] = matrix[i][j].sub(b.matrix[i][j]);
        }
    }
    return res;
}

Matrix Matrix::mul(Matrix b) {
    Matrix res(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res.matrix[i][j] = matrix[i][j].mul(b.matrix[i][j]);
        }
    }
    return res;
}

Matrix Matrix::div(Matrix b) {
    Matrix res(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            res.matrix[i][j] = matrix[i][j].div(b.matrix[i][j]);
        }
    }
    return res;
}

int main(){
    rational a (1,2);
    rational b (1,4);
    a.show_rational();
    b.show_rational();
    a.norm();
    b.norm();
    cout<<"Summa ravna ";
    a.add(b).show_rational();
    cout<<endl;
    cout<<"Raznost ravna ";
    a.mul(b).show_rational();
    cout<<endl;
    cout<<"Proizvedenie ravno ";
    a.div(b).show_rational();
    cout<<endl;

    int rows, cols;
    cout << "Vvedite razmer matric (rows cols): ";
    cin >> rows >> cols;
    Matrix mat1(rows, cols);
    Matrix mat2(rows, cols);
    cout << "Vvedite elementy pervoy matricy:" << endl;
    mat1.input();
    cout << "Vvedite elementy vtoroy matricy:" << endl;
    mat2.input();
    cout << "Matrica 1:" << endl;
    mat1.show_matrix();
    cout << "Matrica 2:" << endl;
    mat2.show_matrix();
    cout << "Summa matric:" << endl;
    mat1.add(mat2).show_matrix();
    cout << "Raznost matric:" << endl;
    mat1.sub(mat2).show_matrix();
    cout << "Proizvedenie matric:" << endl;
    mat1.mul(mat2).show_matrix();
    cout << "Chastnoe matric:" << endl;
    mat1.div(mat2).show_matrix();
    char r;
    cin>>r;
    return 0;
}