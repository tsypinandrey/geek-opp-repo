/*файл: prototype.cpp
 *автор: Цыпин Андрей
 *дата: 11.03.2021
 *операционная система: ubuntu
 *задание: 4
 */

#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>
#include <iomanip>
#include <vector> // класс динамического массива
#include <algorithm>
#include <cassert> // для assert
#include <set> // для set
#include <string>

using std::cout;
using std::endl;
using std::cin;

void clrscr(void); // очиска икрана
void Glmenu(); // главное меню
void menuWorkArray(); // вспомогательное меню
void menuWorkVector(); // вспомогательное меню
void Task1(); // решение задачи №1
void Task2(); // решение задачи №2
void Task3(); // решение задачи №3
void Task4(); // решение задачи №4
int NumberLength(int k); // проверка ввода числа
int NumberNum(int k); // проверка ввода числа

class ArrayInt{ // контейнерный класс
private:
    int m_length; // размер массива
    int *m_data;  // адрес первого элемента
public:
    ArrayInt(); // конструктор по умолчанию
    ArrayInt(int length); // конструктор с параметрами
    ~ArrayInt(); // диструктор освобождения выделеной памяти
    void erase(); // метод очистки массива и сброса длины
    bool isempty(); // если массив пустой
    int getLength(); // метод возращает длину массива
    int& operator[] (int index); // перегрука оператора [], чтобы иметь доступ к элементам массива
    void resize(int newLength); // метод resize изменяет размер массива, с сохранением данных
    void insertBefore(int value, int index); // метод добавления нового элемента в массив
    void push_back(int value); // вставка нового элемента в конец массива
    void pop_back(); // Удаление последнего элемента массива
    void pop_front(); // Удаление первого элемента массива
    void prinArray(); // вывод на экран массива
    void sortArrayUp(); // сортировка массива по возростанию
    void sortArrayDown(); // сортировка массива по возростанию
};

//**************************************************

class Card {
public:
    enum rank { // перечисление значений карт
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING
    };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES }; // перечисление масти карт

    Card(rank r = ACE, suit s = SPADES, bool ifu = true); // конструктор
    int GetValue() const; // метод возращает значение карты
    void Flip(); // метод положение каты, рубашкой верх, лицом верх

private:
    rank m_Rank; // значение карты
    suit m_Suit; // масть карты
    bool m_IsFaceUp; // положение карты
};

class Hand
{
public:
    Hand(); // конструктор по умолчанию
    virtual ~Hand(); // виртуальный деструктор
    void Add(Card* pCard); // добавляет карту в руку
    void Clear(); // очищает руку от карт
    //получает сумму очков карт в руке, присваивая тузу
    // значение 1 или 11 в зависимости от ситуации
    int GetTotal() const;

protected:
    std::vector <Card*> m_Cards;
};

#endif // PROTOTYPE_H
