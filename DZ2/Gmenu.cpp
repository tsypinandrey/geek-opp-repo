#include <iostream>
#include <string>
#include <cstdint>
#include "prototype.h"

using std::cout;
using std::endl;
using std::cin;

void clrscr(void) { // Очистка экрана
    system("@cls||clear");
}

void Glmenu(){
    clrscr(); // очищаем экран
    cout << "Какое задание выполнить?" << endl;
    cout << "1. Создание класса Person и производный класс Student" << endl;
    cout << "2. Создание классы Apple и Banana, которые наследуют класс Fruit" << endl;
    cout << "3. Изучить правила игры в Blackjack, написать сколько будет классов в программе." << endl;
    cout << "4. Выйти из программы" << endl;
    cout << "Ваш выбор: ";
}

void Smenu(){
    cout << "1. - Добавить в список одного студента" << endl;
    cout << "2. - Изменить год обучения студента" << endl;
    cout << "3. - Вывести одного студента по запросу" << endl;
    cout << "4. - Вывести список всех студентов" << endl;
    cout << "5. - Завершить работу и выйти." << endl;
    cout << "Ваш выбор: ";
}

void Task1(){
    clrscr(); // очищаем экран
    cout << "Задние №1." << endl;
    cout << "Сколько студентов в граппе будет у Вас: ";
    int c = 0; // размер массива(количество студентов в группе
    int top = 0; // вершина стека массива
    c = Number(c); // проверка ввода числа, если символ или строка, то свё отбросить и повторить ввод
    cout << endl;
    Smenu();
    Student *grupa = new Student[c];
    char ch;
    while (cin >> ch && ch != '5') {
        cout << endl;
        switch (ch) {
            case '1':
                if (top >= 0 && top < c){
                    grupa[top++].getStudent();
                } else {
                    cout << "Список стедентов заполнен!" << endl;
                }
                cin.get();
                break;
            case '2':
                if (top == 0) {
                    cout << "Список пуст, он не заполнен, добавьте в список студента." << endl;
                }
                else {
                    grupa[top].printCol();
                    for (int i = 0; i < top; ++i){
                        cout << i + 1 << ")";
                        grupa[i].printStudent(2);
                    }
                    int y = 0;
                    cout << "Введите номер студента которому надо изменить год учебы: ";
                    y = Number(y);
                    (grupa + (y - 1))->getYear();
                    grupa[y - 1].printStudent(2);
                }
                cin.get();
                break;
            case '3':
                if (top == 0) {
                    cout << "Список пуст, он не заполнен, добавьте в список студента." << endl;
                }
                else {
                    grupa[top].printCol();
                    for (int i = 0; i < top; ++i){
                        cout << i + 1 << ")";
                        grupa[i].printStudent(3);
                    }
                    int f = 0;
                    cout << "Введите номер студента данные которого надо вывести на экран: ";
                    f = Number(f);
                    grupa[f - 1].printStudent(1);
                }
                cin.get();
                break;
            case '4':
                if (top == 0) {
                    cout << "Список пуст, он не заполнен, добавьте в список студента." << endl;
                }
                else {
                        grupa[top].printCol();
                        for (int i = 0; i < top; ++i){
                            cout << i + 1 << ")";
                            grupa[i].printStudent(1);
                        }
                }
                cin.get();
                break;
            case '5': break;
            default: while (cin.get() != '\n'){} // если ввели строку, то всё отбросить
                cout << "Вы ввели неверное значение, введите от 1 до 5: ";
        }
        cout << "Для продолжения нажмите <Enter>: ";
        while (cin.get() != '\n') {}
        clrscr(); // очищаем экран
        cout << "Задние №1." << endl;
        cout << "Ваша группа расчитана на " << c << " студентов." << endl;
        grupa[top].printCol();
        cout << endl;
        Smenu();
    }
    delete []grupa; // освобождение выделеной памяти
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task2(){
    Apple a("red");
    Banana b;
    GrannySmith c;
    cout << "My " << a.getName() << " is " << a.getColor() << endl;
    cout << "My " << b.getName() << " is " << b.getColor() << endl;
    cout << "My " << c.getName() << " is " << c.getColor() << endl;
    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    cin.get();
    clrscr(); // очищаем экран
    Glmenu(); // вывод меню на экран
}

void Task3(){
    cout << "   Игра Blackjack: "  << endl;
    cout << "Раздаются карты, за каждую из которых начисляются очки. " << endl;
    cout << "   Игрок пытается заработать 21 очко, не больше. За каждую карту с числом дается столько очков," << endl;
    cout << "сколько на ней указано. За туз — либо 1 очко, либо 11 (что больше подходит игроку)," << endl;
    cout << "а за валета, даму и короля — по 10 очков." << endl;
    cout << "   Крупье играет против группы от одного до нескольких игроков. В начале кона все участники," << endl;
    cout << "включая крупье, получают две карты. Игроки могут видеть все свои карты, а также сумму очков." << endl;
    cout << "   Однако одна из карт крупье скрыта на протяжении всего кона." << endl;
    cout << "   Далее каждый игрок может брать дополнительные карты. Если сумма очков у него превысит 21," << endl;
    cout << "он проигрывает. Когда все игроки получили возможность набрать дополнительные карты," << endl;
    cout << "крупье открывает скрытую карту. Далее он обязан брать новые карты до тех пор," << endl;
    cout << "пока сумма его очков не превышает 16. Если у крупье перебор, все игроки, не имеющие перебора," << endl;
    cout << "побеждают. В противном случае сумма очков каждого из оставшихся игроков сравнивается с суммой" << endl;
    cout << "очков крупье. Игрок побеждает, если сумма его очков больше, чем у крупье." << endl;
    cout << "   В противном случае — проигрывает. Если суммы очков игрока и крупье одинаковы, засчитывается ничья." << endl;
    cout << endl <<"Классы для игры Blackjack:" << endl;
    cout << "1) описание карты - родительского класса нет" << endl;
    cout << "2) колода карт - родительского класса нет" << endl;
    cout << "3) тусование и раздача - родительский класс 2" << endl;
    cout << "4) Вертуальный игрок - родительский класс 2" << endl;
    cout << "5) Игрок - родительский класс 4" << endl;
    cout << "6) крупье - родительский класс 4" << endl;
    cout << "7) Игра - родительского класса нет" << endl;
    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    cin.get();
    clrscr(); // очищаем экран
    Glmenu(); // вывод меню на экран
}
