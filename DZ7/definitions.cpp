/*файл: definitions.cpp
 *автор: Цыпин Андрей
 *дата: 22.03.2021
 *операционная система: ubuntu
 *задание: 7
 */

#include "prototype.h"

Date::Date(){
    day = 0; month = 0; year = 0;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y){}
void Date::GetDay(int d){day = d;} // ввод дня
void Date::GetMonth(int m) {month = m;} // ввод месяца
void Date::GetYear(int y) {year = y;} // ввод года
void Date::GetDayMonthYear(int d, int m, int y){day = d, month = m, year = y;} // ввод дня, месяца, года
ostream& operator<<(ostream &out, const Date &a){ // Перегрузка оператора вывода << через дружественную функцию
    out << a.day << "." << a.month << "." << a.year << endl;
    return out;
};
unique_ptr<Date>& Date::compareDate(unique_ptr<Date> &a, unique_ptr<Date> &b){

    return a->day > b->day ? a : b;
}
void Date::exchengeDate(unique_ptr<Date> &a, unique_ptr<Date> &b){
    unique_ptr<Date> temp(new Date);
    temp = move(a);
    a = move(b);
    b = move(temp);
}
