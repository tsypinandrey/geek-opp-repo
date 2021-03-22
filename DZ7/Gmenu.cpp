/*файл: Gmenu.cpp
 *автор: Цыпин Андрей
 *дата: 22.03.2021
 *операционная система: ubuntu
 *задание: 7
 */

#include "prototype.h"
#include "black.h"

using std::cout;
using std::endl;
using std::cin;

double x = 0, y = 0;
char ch = 2;

void clrscr(void) { // Очистка экрана
    system("@cls||clear");
}

void Glmenu(){
    clrscr(); // очищаем экран
    cout << "Какое задание выполнить?" << endl;
    cout << "1. Задание 1." << endl;
    cout << "2. Задание2." << endl;
    cout << "3. Игра в Blackjack." << endl;
    cout << "4. Выйти из программы" << endl;
    cout << "Ваш выбор: ";
}

void Task1(){
    clrscr(); // очищаем экран
    Date date3; // создание экземпляра класса Date(инициализируем по умолчанию поля нулями)
    cout << "date3: " << date3; // вывод на экран экземпляра класса date1
    date3.GetDayMonthYear(21,03,2021); // ввод даты, месяца, года
    cout << "date3: " << date3; // вывод на экран экземпляра класса date1
    date3.GetDay(31); // ввод даты
    date3.GetMonth(04); // ввод месяца
    date3.GetYear(2022); // ввод года
    cout << "date3: " << date3; // вывод на экран экземпляра класса date1
    unique_ptr<Date> today(new Date); // создаём умный указатель date
    unique_ptr<Date> date(new Date);  // создаём умный указатель today
    today->GetDay(16); // ввод даты через указатель
    today->GetMonth(02); // ввод месяца через указатель
    today->GetYear(2021); // ввод года через указатель
    cout << "today: " << *today; // вывод на экран экземпляра указателя today на класс Date
    date = move(today); // присваеваем указателю date адресс данных today, а указателю today присваеваем null
    cout << "date: " << (static_cast<bool>(date) ? "not null\n" : "null\n"); // проверка указателя на null
    cout << "today: " << (static_cast<bool>(today) ? "not null\n" : "null\n"); // проверка указателя на null
    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task2(){
    clrscr(); // очищаем экран
    unique_ptr<Date> date1(new Date), date2(new Date);
    date1->GetDayMonthYear(1,12,2019); // ввод даты, месяца, года через указатель
    date2->GetDayMonthYear(25,12,2019); // ввод даты, месяца, года через указатель
    cout << "dat1: " << *date1; // вывод на экран данных экземпляра указателя date1
    cout << "dat2: " << *date2;// вывод на экран данных экземпляра указателя date2
    cout << "Более поздняя дата: " << *date1->compareDate(date1, date2); // функция возращает более
    // позднию дату после сравнения двух дат
    date1->exchengeDate(date2, date1); // функция обменивает данными двух умных указателей
    cout << endl << "Обмен данными двух умных указателей." << endl;
    cout << "date1: " << *date1;
    cout << "date2: " << *date2;
    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task3(){
    clrscr(); // очищаем экран
    cout << "\t\tДобро пожаловать в Blackjack. Удачной игры!\n\n";
    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7) {
      cout << "Сколько будет играков? Выбирете от 1 до 7 играков: ";
      cin  >> numPlayers;
    }
    vector <string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i) {
      cout << "Введите имя игрока: ";
      cin  >> name;
      names.push_back(name);
    }
    cout << endl;
    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N') {
      aGame.Play();
      cout << "\nВы хотите играть снова? (Y/N): ";
      cin  >> again;
    }

    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

