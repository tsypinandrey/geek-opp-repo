/*файл: Gmenu.cpp
 *автор: Цыпин Андрей
 *дата: 25.03.2021
 *операционная система: ubuntu
 *задание: 8
 */

#include "prototype.h"

using std::cout;
using std::endl;
using std::cin;

char ch = '1';
double x = 0, y = 0;

void clrscr(void) { // Очистка экрана
    system("@cls||clear");
}

void Glmenu(){
    clrscr(); // очищаем экран
    cout << "Какое задание выполнить?" << endl;
    cout << "1. Реализация функции div." << endl;
    cout << "2. Реализация класса Ex и класса Bar." << endl;
    cout << "3. Реализация класса Робот." << endl;
    cout << "4. Выйти из программы" << endl;
    cout << "Ваш выбор: ";
}

void Task1(){
    clrscr(); // очищаем экран
    cout << "Задание 1. Деление дух чисел." << endl;
    do {
        switch(ch){
            case('1'):
                try {
                    cout << "Введите первое число: ";
                    x = Number(x);
                    cout << "Введите второе число: ";
                    y = Number(y);
                    div1(x, y);
                     }
                catch (const char * exception) {
                    std::cerr << exception << "\nОшибка! Делитель не может быть равен 0." << endl;
                }
            break;
            default: while (cin.get() != '\n'){} // если ввели строку, то всё отбросить
            cout << "Вы ввели неверное значение, введите от 1 до 2: " << endl;
        }
        cout << "Введите <1> - продолжить, <2> - завершить" << endl;
        cout << "Ваш выбор: ";
    } while (cin >> ch && ch != '2');
    ch = '1';
    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task2(){
    clrscr(); // очищаем экран
    cout << "Задание 2." << endl;
    Bar s;
    do {
        switch(ch){
            case('1'):
                try {
                    cout << "Введите число: ";
                     x = NumberBar(x);
                     s.set(x);
                    }
                catch (Ex &err) {
                     std::cerr << "Ошибка: Сумма (y + a) = " << err.x << " > 100" << std::endl;
                     std::cerr << " <y> остаётся без изменеий ";
                     s.printBar();
                }
            break;
            default: while (cin.get() != '\n'){} // если ввели строку, то всё отбросить
            cout << "Вы ввели неверное значение, введите от 1 до 2: " << endl;
        }
        cout << "Введите <1> - продолжить, <2> - завершить" << endl;
        cout << "Ваш выбор: ";
    } while (cin >> ch && ch != '2');
    ch = '1';
    cout << "Для продолжения нажмите <Enter>: ";
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task3(){
    clrscr(); // очищаем экран
    Robot a, b;
   initArr();
   printArr();
    do {
        switch(ch){
            case('1'):
                try {
                      a.GetRoute();
                    }
                catch (const char * str) {
                     std::cerr << str << endl;
                }
            break;
            default: while (cin.get() != '\n'){} // если ввели строку, то всё отбросить
                     cout << "Вы ввели неверное значение, введите от 1 до 2: " << endl;
        }
        cout << "Введите <1> - продолжить, <2> - завершить" << endl;
        cout << "Ваш выбор: ";
    } while(cin >> ch && ch != '2');
    ch = '1';
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

