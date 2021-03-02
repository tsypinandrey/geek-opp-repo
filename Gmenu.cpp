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
    cout << "1. Создание класса Power" << endl;
    cout << "2. Создание класса RGBA" << endl;
    cout << "3. Создание класса Stack" << endl;
    cout << "4. Выйти из программы" << endl;
    cout << "Ваш выбор: ";
}

void Smenu(){
    cout << "<A> - добавить число в стек" << endl;
    cout << "<P> - удалить число из стека" << endl;
    cout << "<S> - сброс стека" << endl;
    cout << "<Q> - Завершить работу и выйти." << endl;
    cout << "Ваш выбор: ";
}

void Task1(){
    Power A;
    double m = 0;
    int n = 0, f = 0;
    char ch = '1';
    do {
         switch(ch){
         case '1' :
                if (f == 1)
                clrscr(); // очищаем экран
                cout << "Реализация задание 1" << endl;
                cout << "Введите число: ";
                m = Number(m, 'm'); // присвоение основания числа
                cout << "Введите степень числа: ";
                n = Number(n, 'n'); // присвоение показателя степени
                A.set(m, n); // создание объекта
                A.Calculate();  // вывоз результата возведения в степени
                cout << "Для завершения введите <0> для продолжения <1>" << endl;
                cout << "Ваш выбор: ";
                f = 1;
             continue;
         default: cout << "Вы ввели неверное значение, введите от <0> или <1> : ";
         }
   } while (cin >> ch && ch != '0');
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task2(){
    char ch = '1';
    int f = 1, a = 0, b = 0, c = 0, d = 0;
    do {
         switch(ch){
         case '1' :
                if (f == 1)
                clrscr(); // очищаем экран
                cout << "Реализация задание 2" << endl;
                cout << "Введите значение m_red: ";
                a = Number(a, 'a');
                cout << "Введите значение m_dreen: ";
                b = Number(b, 'b');
                cout << "Введите значение m_blue: ";
                c = Number(c, 'c');
                cout << "Введите значение m_alpha: ";
                d = Number(d, 'd');
                 {                       // скобки обязательны
                    RGBA B(a, b, c, d);  // создаем локальный объект класса
                    B.printRGBA();
                 }
                cout << "Для завершения введите <0> для продолжения <1>" << endl;
                cout << "Ваш выбор: ";
                f = 1;
             continue;
         default: cout << "Вы ввели неверное значение, введите от <0> или <1> : ";
         }
   } while (cin >> ch && ch != '0');
    clrscr(); // очищаем экран
    Glmenu(); // вывод меню на экран
}

void Task3(){
    Stack st;
    char ch;
    int num;
    clrscr(); // очищаем экран
    cout << "3. Создание класса Stack" << endl;
    Smenu();
    while(cin >> ch && toupper(ch) != 'Q'){
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch)){
            cout << "Неверный ввод!" << endl;
            Smenu();
            continue;
        }
        switch (ch) {
        case 'A':
        case 'a': cout << "Введите число: ";
            cin >> num;
            if (st.isfull())
                cout << "Стек заполнен!" << endl;
            else {
                st.push(num);
                st.printStack();
            }
            break;
        case 'P':
        case 'p': if (st.isempty())
                       cout << "Стек пуст!" << endl;
                  else {
                       st.pop(num);
                       cout << "Число: " << num << " удалено из стека" << endl;
                       st.printStack();
                   }
            break;
        case 'S':
        case 's': if (st.isempty())
                    cout << "Стек пуст!" << endl;
                  else {
                    st.reset();
                    st.printStack();
            }
            break;
        }
        Smenu();
    }
    cout << "Конец!" << endl;
    clrscr(); // очищаем экран
    Glmenu(); // вывод меню на экран
}
