#include <iostream>
#include "prototype.h"
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

int Student::col = 0; // инициализация статической переменной

Person::Person(){ // конструктор по умолчанию
    name = "Неизвестно";
    surname = "Неизвестно";
    gender = "Неизвестно";
    weight = 0.0;
}

Person::Person(string n, string s, string g, float w):
    name(n), surname(s), gender(g), weight(w){}// конструктор с параметрами

void Person::getPerson(){ // ввод данных на человека
  cin.get();
  cout << "Введите имя студента: ";
  getline(cin, name);
  cout << "Введите фамилию студента: ";
  getline(cin, surname);
  cout << "Введите пол студента: ";
  getline(cin, gender);
  cout << "Введите вес студента: ";
  weight = Number(weight); // присвоение основания числа
}

void Person::prinfPerson(int num){ // вывод на экран данных на человека
    if (num == 1){
        cout << " " << name << " " << surname
            << ", пол - " << gender << ", вес - " << weight;
    } else if (num == 2){
        cout << " " << name << " " << surname << " - ";
    } else if (num == 3){
        cout << " " << name << " " << surname;
    }
}

Student::Student(){ // конструктор по умолчанию
    year = 0;
}

Student::Student(string n, string s, string g, float w, int y):
    Person(n, s, g, w), year(y) {} // конструктор с параметрами

Student::~Student(){} // диструктор

void Student::getStudent(){ //ввод данных на студента
    getPerson();
    cout << "Введите год обучения: ";
    year = Number(year); // присвоение основания числа
    col++;
}
void Student::getYear(){  // ввод год обучения студента
    cout << "Введите год обучения: ";
    cin >> year;
}
void Student::printStudent(int num){ // вывод на экран данных на судента
    prinfPerson(num);
    if (num == 1){
    cout << ", год обучения: " << year << endl;
    } else if (num == 2){
        cout << "год обучения: " << year << endl;
    } else if (num == 3){
        cout << endl;
    }
}

void Student::printCol(){ // выводит количестко студентов
    cout << "Всего студентов в списке: " << col << endl;
}

template <typename N> // определение проверка ввода числа
N Number(N k){
    while (!(cin >> k) || (cin.peek() != '\n') || k <=0){
        cin.clear();
        while (cin.get() != '\n') {};
            cout << "Это неверный ввод! Введите число: ";
    }

    return k;
}

// **************************************

Fruit::Fruit(string n, string c) : f_name(n), f_color(c) {} // конструктор с параметрами

string Fruit::getName(){ // ввод название фрукта
    return f_name;
}

string Fruit::getColor(){ // ввод цвета фрукта
    return f_color;
}

Apple::Apple(string c): Fruit("apple", c){} // конструктор с параметрами

Banana::Banana(): Fruit("banana", "yellow"){} // конструктор по умолчанию

GrannySmith::GrannySmith(): Apple("green"){} // конструктор по умолчанию


