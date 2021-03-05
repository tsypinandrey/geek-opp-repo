#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>

using std::string;

void clrscr(void);
void Glmenu();
void Task1();
void Task2();
void Task3();

class Person{
protected:
    string name;      // Имя
    string surname;   // фамилия
    string gender;    // пол человека
    float weight;     // вес человека
public:
    Person(); // конструктор по умолчанию
    Person(string n, string s, string g, float w); // конструктор с параметрами
    void getPerson();   // ввод данных на человека
    void prinfPerson(int num); // вывод на экран данных на человека
};

class Student: public Person{
private:
    int year;       // год обучения
    static int col; // счетчик судентов
public:
    Student(); // конструктор по умолчанию
    Student(string n, string s, string g, float w, int y); // конструктор с параметрами
    ~Student();
    void getStudent();   //ввод данных на студента
    void getYear();      // ввод год обучения студента
    void printStudent(int num); // вывод на экран данных на судента
    void printCol();     // выводит количестко студентов
};

template <typename N> // прототип шаблона проверка ввода числа
N Number(N k);

//************************

class Fruit{
protected:
    string f_name;
    string f_color;
public:
    Fruit(string n, string c); // конструктор с параметрами
    string getName();  // ввод название фрукта
    string getColor(); // ввод цвета фрукта
};

class Apple: public Fruit{
public:
    Apple(string n); // конструктор с параметрами
};

class Banana: public Fruit{
public:
    Banana(); // конструктор по умолчанию
};

class GrannySmith: public Apple{
public:
    GrannySmith(); // конструктор по умолчанию
};

#endif // PROTOTYPE_H
