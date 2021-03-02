/*файл: main.cpp
 *автор: Цыпин Андрей
 *дата: 01.03.2021
 *операционная система: ubuntu
 *задание: 1
 */
#include <iostream>
#include "prototype.h"

using namespace std;

void clrscr(void);
void Glmenu();
void Task1();
void Task2();
void Task3();

int main()
{
    Glmenu(); // вывод меню на экран
    char variant;
    while (cin >> variant && variant != '4')
    switch(variant){
        case '1': Task1(); // выполнение первого задания
            continue;
        case '2': Task2(); // выполнение вторового задания
            continue;
        case '3': Task3(); // выполнение вторового задания
            continue;
        case '4': break;
        default: cout << "Вы ввели неверное значение, введите от 1 до 4: ";
    }
    clrscr(); // очищаем экран
    return 0;
}
