/*файл: main.cpp
 *автор: Цыпин Андрей
 *дата: 22.03.2021
 *операционная система: ubuntu
 *задание: 7
 */
#include "prototype.h"

using namespace std;

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
        case '3': Task3(); // выполнение третьего задания
            continue;
        case '4': break;
        default: while (cin.get() != '\n'){} // если ввели строку, то всё отбросить
            cout << "Вы ввели неверное значение, введите от 1 до 4: ";
    }
    clrscr(); // очищаем экран
    return 0;
}
