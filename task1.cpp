///Задача: Определить класс Children, который содержит такие поля (члены класса):закрытые – имя ребенка, фамилию и возраст,
///публичные – методы ввода данных и отображения их на экран. Объявить два объекта класса, внести данные и показать их.
#include <iostream>
#include <string>
using namespace std;

class Children{
    private:
      string name_child;
      string last_name;
      int age;
     public:
        void vvod();
        void show();
};

void Children::vvod(){
    cout<<"Enter the child's name: ";
    cin>>name_child;
    cout<<"Enter the child's last name: ";
    cin>>last_name;
    cout<<"Enter the child's age: ";
    cin>>age;
    show();
}

void Children::show(){
    cout<<"Name child "<<name_child<<", last name " <<last_name << " and age "<< age;
}

int main() {
   Children ch;
   ch.vvod();
   char r;
   cin>>r;
   return 0;
}