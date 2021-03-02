#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>
#include <cstdint>

class Power {
private:
    double x; // основание числа
    int y;    // показатель степени
public:
    Power () : x(0), y(0){   // конструктор для инициализации полей по умолчанию
    }
    void set (double n, int m); // присвоение новых значений полей переменых
    void Calculate ();       // возведение в степень и вывод на экран
};

template <typename N>
N Number(N k, char ch){
    while (!(std::cin >> k) || (std::cin.peek() != '\n')){
        std::cin.clear();
         while (std::cin.get() != '\n');
         if (ch == 'm' || ch == 'a' || ch == 'b' || ch == 'c' || ch == 'd')
             std::cout << "Неверный ввод! Введите число: ";
         else if(ch == 'n')
             std::cout << "Неверный ввод! Введите степень числа: ";
    }
    return k;
}

class RGBA {
private:
    uint8_t m_red;
    uint8_t m_dreen;
    uint8_t m_blue;
    uint8_t m_alpha;

public:
    RGBA () { // конструктор по умолчанию
        m_red = 0;
        m_dreen = 0;
        m_blue = 0;
        m_alpha = 255;
    }
    RGBA (uint8_t a, uint8_t b, uint8_t c, uint8_t d)  // конструктор с параметрами
        : m_red(a), m_dreen(b), m_blue(c), m_alpha(d){}
    void printRGBA(); // метод вывода на экран значений переменных-членов класса
};

typedef int anytype; // стеку можно задать любой тип

class Stack{
private:
    enum{MAX = 10}; // Константа, для размера массива
    anytype array[MAX]; // Массив стека
    int top;        // Индекс вершины стека
public:
    Stack();        // конструктор по умолчанию(создание пустого стека)
    bool isempty() const;      // если стек пустой
    bool isfull() const;       // если стек заполнен
    bool push(const int & ar); // добавляем элемент в стек
    bool pop(int & ar);        // выталкивает элемент с вершины
    void reset();              // сброс стека
    void printStack();         // вывод на экран содержимого стека
};

#endif // PROTOTYPE_H
