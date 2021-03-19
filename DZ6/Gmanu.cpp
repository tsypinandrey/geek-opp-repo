 /*файл: Gmenu.cpp
 *автор: Цыпин Андрей
 *дата: 19.03.2021
 *операционная система: ubuntu
 *задание: 6
 */

#include "prototype.h"

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
    cout << "1. Провека ввода чисел." << endl;
    cout << "2. Создание собственного манипулятора endll." << endl;
    cout << "3. Создание класса Plaer." << endl;
    cout << "4. Создание класса House" << endl;
    cout << "5. Реализация перегрузки оператора вывода для класса Plaeyr" << endl;
    cout << "6. Выйти из программы" << endl;
    cout << "Ваш выбор: ";
}

void Task1(){
    clrscr(); // очищаем экран
    double k = 0.0;
    char ch = '2';
    do
    {
        cout << "Введите число: ";
        k = Number(k);
        cout << "Это правильный ввод числа: " << k << endl;
        cout << "Завершить <1>, продолжить <2>: ";
        while (cin.get() != '\n');
    }  while (cin >> ch && ch != '1');
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task2(){
    clrscr(); // очищаем экран
    int dd;
    std::string ss;
    cout << "Введите число: ";
    cin >> dd;
    cout << "Ваше число - " << dd << endll;
    cout << "Введите строку: ";
    while (cin.get() != '\n');
    getline(std::cin, ss);
    cout << "Ваша строка - " << ss << endll;
    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task3(){
    clrscr(); // очищаем экран
    cout << "class Player : public GenericPlayer" << endl;
    cout << "{" << endl;
    cout << " public:" << endl;
    cout << "   Player(const std::string& name = "");" << endl;
    cout << "   virtual ~Player();" << endl;
    cout << "   virtual bool IsHitting() const;" << endl;
    cout << "   void Win() const;" << endl;
    cout << "   void Lose() const;" << endl;
    cout << "   void Push() const;" << endl;
    cout << "};" << endl;
    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task4(){
   clrscr(); // очищаем экран
   cout << "class House : public GenericPlayer" << endl;
   cout << "{" << endl;
   cout << "  public:" << endl;
   cout << "    House(const std::string& name = \"Крупье\");" << endl;
   cout << "    virtual ~House();" << endl;
   cout << "    virtual bool IsHitting() const;" << endl;
   cout << "    void FlipFirstCard();" << endl;
   cout << "};" << endl;
   cout << "Для продолжения нажмите <Enter>: ";
   cin.get();
   cin.get();
   clrscr(); // очищаем экран
   Glmenu();  // вывод меню на экран
}

void Task5(){
   clrscr(); // очищаем экран
   cout << "std::ostream& operator<<(std::ostream& os, const Card& aCard)" << endl;
   cout << "{" << endl;
   cout << "  const std::string RANKS[] = {\"0\", \"A\", \"2\", \"3\", \"4\", \"5\", \"6\", \"7\", \"8\", \"9\"," << endl;
   cout << "                           \"10\", \"J\", \"Q\", \"K\"};" << endl;
   cout << "" << endl;
   cout << "  const std::string SUITS[] = {\"c\", \"d\", \"h\", \"s\"};" << endl;
   cout << "" << endl;
   cout << "  if (aCard.m_IsFaceUp)" << endl;
   cout << "      os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];" << endl;
   cout << "  else" << endl;
   cout << "      os << \"XX\";" << endl;
   cout << "" << endl;
   cout << "  return os;" << endl;
   cout << "}" << endl;
   cout << "Для продолжения нажмите <Enter>: ";
   cin.get();
   cin.get();
   clrscr(); // очищаем экран
   Glmenu();  // вывод меню на экран
}
