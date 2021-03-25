/*файл: main.cpp
 *автор: Цыпин Андрей
 *дата: 25.03.2021
 *операционная система: ubuntu
 *задание: 8
 */
#include "prototype.h"

int main()
{
    Glmenu(); // вывод меню на экран
    char variant;
    while (std::cin >> variant && variant != '4')
    switch(variant){
        case '1': Task1(); // выполнение первого задания
            continue;
        case '2': Task2(); // выполнение вторового задания
            continue;
        case '3': Task3(); // выполнение третьего задания
            continue;
        case '4': break;
    default: while (std::cin.get() != '\n'){} // если ввели строку, то всё отбросить
             std::cout << "Вы ввели неверное значение, введите от 1 до 4: ";
    }
    clrscr(); // очищаем экран
    return 0;
}
