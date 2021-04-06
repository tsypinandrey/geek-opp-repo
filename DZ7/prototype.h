/*файл: prototype.h
 *автор: Цыпин Андрей
 *дата: 19.03.2021
 *операционная система: ubuntu
 *задание: 7
 */

#pragma once

#include <iostream>
#include <string>
#include <limits> // для numeric_limits
#include <ios>    // для <streamsize>
#include <vector> // класс динамического массива
#include <algorithm>
#include <ctime>
#include <memory> // для указателя unique_ptr

void clrscr(void);
void Glmenu();
void Task1();
void Task2();
void Task3();

using namespace std;

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date();
    Date(int d, int m, int y);
    void GetDay(int d); // ввод дня
    void GetMonth(int m); // ввод месяца
    void GetYear(int y); // ввод года
    void GetDayMonthYear(int d, int m, int y); // ввод дня, месяца, года
    friend ostream& operator<<(ostream &out, const Date &a); // Перегрузка оператора вывода << через дружественную функцию
    unique_ptr<Date> & compareDate(unique_ptr<Date> &a, unique_ptr<Date> &b);
    void exchengeDate(unique_ptr<Date> &a, unique_ptr<Date> &b);
};
