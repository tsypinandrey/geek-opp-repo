/*файл: Gmenu.cpp
 *автор: Цыпин Андрей
 *дата: 15.03.2021
 *операционная система: ubuntu
 *задание: 5
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
    cout << "1. Создание шаблона класса Pair1 для одной пары данных одного типа." << endl;
    cout << "2. Создание шаблона класса Pair для одной пары данных разных типов." << endl;
    cout << "3. Создание шаблона класса StringValuePair, "
            "в котором первое значение всегда типа string, а второе - любого типа." << endl;
    cout << "4. Создание класса GenericPlayer" << endl;
    cout << "5. Выйти из программы" << endl;
    cout << "Ваш выбор: ";
}

void Task1(){
   do {
        clrscr(); // очищаем экран
        cout << "Задние №1." << endl;
        cout << "Введите первое число: ";
        x = Number(x);
        cout << "Введите второе число: ";
        y = Number(y);
        Pair1<int> p1(x, y); // создаем экземпляр класса типа <int>
        cout << "1) Экземпляр класса типа <int> -> ";
        cout << "Pair1<int>: " << p1.first() << ' ' << p1.second() << '\n';
        const Pair1<double> p2(x, y); // создаем экземпляр класса типа <duoble>
        cout.setf(ios_base::showpoint); // вывод на экране цифр после запятой
        cout << "2) Экземпляр класса типа <duoble> -> ";
        cout << "Pair1<double>: " << p2.first() << ' ' << p2.second() << '\n';
        cout << endl << "Завершить <1>, продолжить <2>: ";
        while (cin.get() != '\n');
    }  while (cin >> ch && ch != '1');
    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task2(){
   do {
        clrscr(); // очищаем экран
        cout << "Задние №2." << endl;
        cout << "Введите первое число: ";
        x = Number(x);
        cout << "Введите второе число: ";
        y = Number(y);
        Pair<int, double> p1(x, y); // создаем экземпляр класса типа <int, double>
        cout.setf(ios_base::showpoint); // вывод на экране цифр после запятой
        cout << "1) Экземпляр класса типа <int, double> -> ";
        cout << "Pair<int, double>: " << p1.first() << ' ' << p1.second() << '\n';
        const Pair<double, int> p2(x, y); // создаем экземпляр класса типа <double, int>
        cout << "1) Экземпляр класса типа <double, int> -> ";
        cout << "const Pair<double, int>: " << p2.first() << ' ' << p2.second() << '\n';
        cout << endl << "Завершить <1>, продолжить <2>: ";
        while (cin.get() != '\n');
    }  while (cin >> ch && ch != '1');
    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task3(){
    cout.setf(ios_base::showpoint); // вывод на экране цифр после запятой
    string str;
   do {
        while (cin.get() != '\n');
        clrscr(); // очищаем экран
        cout << "Задние №3." << endl;
        cout << "Введите Ваше имя: ";
        getline(cin, str);
        cout << "Введите Ваш возраст: ";
        x = Number(x);
        cout << "Введите Ваш вес (0.00): ";
        y = Number(y);
        StringValuePeir<int> SV1(str, x);
        cout << "3) Экземпляр класса типа <int>    -> ";
        cout << "StringValuePeir<int>: " << "   Ваше имя: " << SV1.first() << ' ' <<
                ", и возраст: " << SV1.second() << '\n';
        StringValuePeir<double> SV2(str, y);
        cout << "4) Экземпляр класса типа <double> -> ";
        cout << "StringValuePeir<double>: " << "Ваше имя: " << SV2.first() << ' ' <<
                ", и возраст: " << SV2.second() << '\n';
        cout << endl << "Завершить <1>, продолжить <2>: ";
    }  while (cin >> ch && ch != '1');
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task4(){
   clrscr(); // очищаем экран
   cout << "class GenericPlayer : public Hand // абстрактный класс" << endl;
   cout << "{   " << endl;
   cout << "    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);"
           " //перегрузка оператора вывода <<" << endl;
   cout << "" << endl;
   cout << "public:" << endl;
   cout << "    GenericPlayer(const string& name): m_Name(name){}; // конструктор принимает строку" << endl;
   cout << "    virtual ~GenericPlayer(){}; // виртуальный дисктруктор" << endl;
   cout << "    virtual bool IsHitting() const = 0; // возращает значение будет игрок играть или нет" << endl;
   cout << "    bool IsBusted() const{ // возращает значение если у игрока перебор" << endl;
   cout << "        return (GetTotal() > 21);" << endl;
   cout << "    }" << endl;
   cout << "    void Bust() const{ // выводит на экран если у игрока перебор" << endl;
   cout << "        cout << m_Name << \" busts.\n\";" << endl;
   cout << "    };" << endl;
   cout << "" << endl;
   cout << "protected:" << endl;
   cout << "    string m_Name;" << endl;
   cout << "};" << endl;
   cout << "Для продолжения нажмите <Enter>: ";
   cin.get();
   cin.get();
   clrscr(); // очищаем экран
   Glmenu();  // вывод меню на экран
}
