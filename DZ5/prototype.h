/*файл: prototype.h
 *автор: Цыпин Андрей
 *дата: 15.03.2021
 *операционная система: ubuntu
 *задание: 5
 */
#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>
#include <vector> // класс динамического массива

void clrscr(void);
void Glmenu();
void Task1();
void Task2();
void Task3();
void Task4();

using namespace std;

template <class N> // шаблонный класс для одного типа данных
class Pair1 { // базовый шаблон
private:
    N a;
    N b;
public:
    Pair1(){N a = 0; N b = 0;} // конструктор по умолчанию
    Pair1(N x, N y) : a(x), b(y){} // конструктор с параметрами
    N first() const {return a;} // const - этот метод не изменяет объект
    N second() const {return b;} // const - этот метод не изменяет объект
};

template <class T, class S> // шаблонный класс для двух типов данных
class Pair{ // базовый шаблон
protected:
    T a;
    S b;
public:
    Pair(T x, S y) : a(x), b(y){} // конструктор с параметрами
    T first() const {return a;}
    S second() const {return b;}
};

template <class S> // частичная специализация базового шаблона
class Pair<string, S>{ // базовый шаблон
    string a;
    S b;
public:
    Pair(const string& x, S y) : a(x), b(y){}
    string first() const {return a;}
    S second() const {return b;}
};

template <class A> // наследник частично специалезированого базового шаблона Pair
class StringValuePeir:public Pair<string, A>{
public:
    StringValuePeir(const string& s, int e):Pair<string, A>(s, e){}
};

template <typename N> // определение проверка ввода числа
N Number(N k){
    while (!(cin >> k) || (cin.peek() != '\n')){
        cin.clear();
        while (cin.get() != '\n') {};
            cout << "Это неверный ввод! Введите число: ";
    }
    return k;
}

//******************************************************************

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
    Hand();
    // виртуальный деструктор
    virtual ~Hand();

    // добавляет карту в руку
    void Add(Card* pCard);

    // очищает руку от карт
    void Clear();

    //получает сумму очков карт в руке, присваивая тузу
    // значение 1 или 11 в зависимости от ситуации
    int GetTotal() const;

protected:
    vector<Card*> m_Cards;
};


class GenericPlayer : public Hand // абстрактный класс
{
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer); //перегрузка оператора вывода <<

public:
    GenericPlayer(const string& name): m_Name(name){}; // конструктор принимает строку
    virtual ~GenericPlayer(){}; // виртуальный дисктруктор
    virtual bool IsHitting() const = 0; // возращает значение будет игрок играть или нет
    bool IsBusted() const{ // возращает значение если у игрока перебор
        return (GetTotal() > 21);
    }
    void Bust() const{ // выводит на экран если у игрока перебор
        cout << m_Name << " busts.\n";
    };

protected:
    string m_Name;
};

#endif // PROTOTYPE_H
