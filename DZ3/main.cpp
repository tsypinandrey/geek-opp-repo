/*файл: main.cpp
 *автор: Цыпин Андрей
 *дата: 08.03.2021
 *операционная система: ubuntu
 *задание: 3
 */

#include <iostream>
#include "prototype.h"

using namespace std;

int main()
{
    Glmenu(); // вывод меню на экран
    char variant;
    while (cin >> variant && variant != '5')
    switch(variant){
        case '1': Task1(); // выполнение первого задания
            continue;
        case '2': Task2(); // выполнение вторового задания
            continue;
        case '3': Task3(); // выполнение вторового задания
            continue;
        case '4': Task4(); // выполнение вторового задания
            continue;
        case '5': break;
        default: while (cin.get() != '\n'){} // если ввели строку, то всё отбросить
            cout << "Вы ввели неверное значение, введите от 1 до 5: ";
    }
    clrscr(); // очищаем экран
    return 0;
}
