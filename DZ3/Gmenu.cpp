#include <iostream>
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
    cout << "1. Создание абстрактного класса Figure(фигура) и его наследников." << endl;
    cout << "2. Создание класса Car(автомобиль) и его наследников.." << endl;
    cout << "3. Создание класса Fraction(дробь) и перегрузить различные операторы." << endl;
    cout << "4. Создание класса Card, и описать карту в игре Blackjack." << endl;
    cout << "5. Выйти из программы" << endl;
    cout << "Ваш выбор: ";
}

void menuFigure(){
    cout << "Какую площадь фигуры расчитать?" << endl;
    cout << "1. - Паралелограмм." << endl;
    cout << "2. - Круг." << endl;
    cout << "3. - Прямоугольник." << endl;
    cout << "4. - Квадрат" << endl;
    cout << "5. - Ромб" << endl;
    cout << "6. - Завершить работу и выйти." << endl;
    cout << "Ваш выбор: ";
}

void menuFraction(){
    cout << "Какую операцию с дробью расчитать?" << endl;
    cout << "1. - Сложение." << endl;
    cout << "2. - Вычитание." << endl;
    cout << "3. - Умножение." << endl;
    cout << "4. - Деление" << endl;
    cout << "5. - Завершить работу и выйти." << endl;
    cout << "Ваш выбор: ";
}

void Task1(){
    clrscr(); // очищаем экран
    cout << "Задние №1." << endl;
    menuFigure();
    Paralelogram P;
    Circle C;
    Rectangle R;
    Square S;
    Rhombus Rh;
    float x = 0, y = 0;
    char ch;
    while (cin >> ch && ch != '6') {
        switch (ch) {
            case '1':
                cout << "Введите длину паралелограмма: ";
                x = Number(x);
                cout << "Введите ширину паралелограмма: ";
                y = Number(y);
                P.getParalelogram(x, y);
                cout << endl;
                P.printfigure();
                P.area();
                break;
            case '2':
                cout << "Введите радиус круга: ";
                x = Number(x);
                C.getCircle(x);
                cout << endl;
                C.printfigure();
                C.area();
                break;
            case '3':
                cout << "Введите длину прямоугольника: ";
                x = Number(x);
                cout << "Введите ширину прямоугольника: ";
                y = Number(y);
                R.getParalelogram(x, y);
                cout << endl;
                R.printfigure();
                R.area();
                break;
            case '4':
                cout << "Введите длину квадрата: ";
                x = Number(x);
                S.getParalelogram(x, x);
                cout << endl;
                S.printfigure();
                S.area();
                break;
            case '5':
                cout << "Введите длину ромба: ";
                x = Number(x);
                cout << "Введите ширину ромба: ";
                y = Number(y);
                Rh.getParalelogram(x, y);
                cout << endl;
                Rh.printfigure();
                Rh.area();
                break;
            default: while (cin.get() != '\n'){} // если ввели строку, то всё отбросить
                cout << "Вы ввели неверное значение, введите от 1 до 6: ";
        }
        cout << endl << "Для продолжения нажмите <Enter>: ";
        while (cin.get() != '\n') {}
        cin.get();
        clrscr(); // очищаем экран
        cout << "Задние №1." << endl;
        menuFigure();
    }
    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task2(){
    Car E("Mercedes-Benz", "E-200");
    cout << "*************************" << endl;
    PassengerCar A("Mercedes-Benz","A-200","White");
    cout << "*************************" << endl;
    Bus B("Mercedes-Benz", "Sprinter Kombi", 9);
    cout << "*************************" << endl;
    Miniven("Mercedes-Benz","Vito Strong Long","Black", 5, 7);
    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    cin.get();
    clrscr(); // очищаем экран
    Glmenu(); // вывод меню на экран
}

void Task3(){
    clrscr(); // очищаем экран
    cout << "Задние №3." << endl;
    menuFraction();
    char ch;
    while (cin >> ch && ch != '5') {
        switch (ch) {
            case '1':
                cout << "Сложение: " << endl;
                addFractions();
                break;
            case '2':
                cout << "Вычитание: " << endl;
                subtractFractions();
                break;
            case '3':
                cout << "Умножение: " << endl;
                multiplyFractions();
                break;
            case '4':
                cout << "деление: " << endl;
                divideFractions();
                break;
            default: while (cin.get() != '\n'){} // если ввели строку, то всё отбросить
                cout << "Вы ввели неверное значение, введите от 1 до 5: ";
        }
        cout << endl << "Для продолжения нажмите <Enter>: ";
        while (cin.get() != '\n') {}
        cin.get();
        clrscr(); // очищаем экран
        cout << "Задние №1." << endl;
        menuFraction();
    }
    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task4(){
   clrscr(); // очищаем экран
   cout << " class Card {" << endl;
   cout << " public:" << endl;
   cout << "    enum rank { // перечисление значений карт" << endl;
   cout << "        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN," << endl;
   cout << "        JACK, QUEEN, KING" << endl;
   cout << "    };" << endl;
   cout << "    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES }; // перечисление масти карт" << endl;
   cout << "" << endl;
   cout << "    Card(rank r = ACE, suit s = SPADES, bool ifu = true); // конструктор" << endl;
   cout << "    int GetValue() const; // метод возращает значение карты" << endl;
   cout << "    void Flip(); // метод положение каты, рубашкой верх, лицом верх" << endl;
   cout << " " << endl;
   cout << " private:" << endl;
   cout << "    rank m_Rank; // значение карты" << endl;
   cout << "    suit m_Suit; // масть карты" << endl;
   cout << "   bool m_IsFaceUp; // положение карты" << endl;
   cout << " };" << endl;
   cout << "Для продолжения нажмите <Enter>: ";
   cin.get();
   cin.get();
   clrscr(); // очищаем экран
   Glmenu();  // вывод меню на экран
}
