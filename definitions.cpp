#include <iostream>
#include "prototype.h"

void Power::set (double n, int m) { // присвоение новых значений полей переменых
    x = n;
    y = m;
}

void Power::Calculate () { // возведение в степень и вывод на экран
    double sum = 1.0, n = abs(y);
    if (y > 0) {
        for (; n > 0; --n) {
            sum = sum * x;
        }
    } else if (y < 0){
        for (; n > 0; --n) {
            sum = sum * x;
        }
        sum = 1 / sum;
    } else if (y == 0) sum = x;
    std::cout << "x = " << x << " y = " << y << " sum = " << sum << std::endl;
}

void RGBA::printRGBA() {
    std::cout << "m_red = " << m_red << ", m_dreen = " << m_dreen << ", m_blue = " <<
            m_blue << ", m_alpha = " << m_alpha << std::endl;
}

Stack::Stack(){ // создание пустого стека
    top = 0;
}

bool Stack::isempty() const{ // возвращает 0 если стек пустой
    return  top == 0;
}

bool Stack::isfull() const{ // возвращает MAX eсли стек заполней
    return top == MAX;
}

bool Stack::push(const anytype &ar){ // возвращяет false, если стек заполнен, и true - в противном случае
    if (top < MAX){
        array[top++] = ar;
        return true;
    } else
        return false;
}

bool Stack::pop(anytype & ar){ // возвращяет false, если стек пуст, и true - в противном случае
    if (top > 0){
        ar = array[--top];
        return true;
    } else
        return false;
}

void Stack::reset() { // сброс стека
    int n = top;
        for (int i = 0; i < n; ++i)
            top--;
        std::cout << "Стек сброшен." << std::endl;
}

void Stack::printStack(){ // вывод на экран содержимого стека
    if (top == 0)
        std::cout << "Стек пуст!";
    else {
        std::cout << std::endl << "Размер стека " << MAX << std::endl;
        std::cout << "Занято ячеек в стеке " << top << ", свободных ячеек в стеке " << MAX - top << std::endl;
        std::cout << "Значения стека -> ";
        for (int i = 0; i < top; ++i)
            std::cout << array[i] << " ";
    }
    std::cout << "\n\n";
}
