/*файл: prototype.h
 *автор: Цыпин Андрей
 *дата: 25.03.2021
 *операционная система: ubuntu
 *задание: 8
 */

#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>

#define DX 10 // граница поля по х
#define DY 10 // граница поля по у

void clrscr(void);
void Glmenu();
void Task1();
void Task2();
void Task3();
void printArr ();
void initArr();

template <typename T>
void div1(T a, T b){
        if (b != 0) std::cout << a << " / " << b << " = " << a / b << std::endl;
        else throw  "DivisionByZiro";
}

template <typename N> // определение проверки ввода числа
N Number(N k){
    while (!(std::cin >> k) || (std::cin.peek() != '\n')){
        std::cin.clear();
        while (std::cin.get() != '\n') {};
            std::cout << "Это неверный ввод! Введите число: ";
    }
    return k;
}

//*****************************

class Ex{
public:
    double x;
    Ex(const double &a): x(a){}
};

class Bar {
private:
    double y;
public:
    Bar(){y = 0;}
    ~Bar(){}
    void set(const double &a){
        if (y + a >= 100) {
            std::cout << " y = " << y << ", a = " << a << std::endl;
            throw Ex(y + a);
        }
        else {
            std::cout << " y = " << y << ", a = " << a << std::endl;
            std::cout << "Сумма (y + a) = " << a + y << " <= 100" << std::endl;
            std:: cout << " <y> присваиваем <a> " << " -> y = " << a << std::endl;
            y = a;
        }
    }
    void printBar(){
        std::cout << "y = " << y << std::endl;
    }
};

template <typename N> // определение проверки ввода числа
N NumberBar(N k){
    while ((!(std::cin >> k) || (std::cin.peek() != '\n')) && k != 0){
        std::cin.clear();
        while (std::cin.get() != '\n') {};
            std::cout << "Это неверный ввод! Введите число: ";
    }
    return k;
}

//************************************************

class Robot{
private:
    int x; // координата х
    int y; // координата у
    char route; // направление перемещения робота
public:
    Robot(){x = 0; y = 0; route = ' ';}
    ~Robot(){}
    void GetRoute();
    void GetXY(int &x_x, int &y_y);
    void printRobot(int x_x, int y_y, char r);
};

char ValueChar(char c);


