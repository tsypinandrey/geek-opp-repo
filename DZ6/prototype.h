/*файл: prototype.h
 *автор: Цыпин Андрей
 *дата: 19.03.2021
 *операционная система: ubuntu
 *задание: 6
 */
#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>
#include <string>
#include <limits> // для numeric_limits
#include <ios>    // для <streamsize>
#include <vector> // класс динамического массива
#include <algorithm>
#include <ctime>

void clrscr(void);
void Glmenu();
void Task1();
void Task2();
void Task3();
void Task4();
void Task5();

std::ostream& endll(std::ostream& os); // собственный манипулятор двойного перевода строки

template <typename N> // определение проверка ввода числа
N Number(N k){
    while (!(std::cin >> k) || (std::cin.peek() != '\n')){
        std::cin.clear();
        while (std::cin.get() != '\n') {};
            std::cout << "Это неверный ввод! Введите число: ";
    }
    return k;
}

//******************************************
//using namespace std;

class Card
{
public:
  enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
           JACK, QUEEN, KING}; // перечисление значений карт
  enum suit {CLUBS, DIAMONDS, HEARTS, SPADES}; // перечисление масти карт
  friend std::ostream& operator<<(std::ostream& os, const Card& aCard);
  Card(rank r = ACE, suit s = SPADES, bool ifUp = true);
  int GetValue() const; // метод возращает значение карты
  void Flip();  // метод положение каты, рубашкой верх, лицом верх
private:
  rank m_Rank; // значение карты
  suit m_Suit; // масть карты
  bool m_IsFaceUp; // положение карты
};

class Hand
{
public:
  Hand();
  virtual ~Hand();
  void Add(Card* pCard);
  void Clear();
  int GetTotal() const;
protected:
  std::vector <Card*> m_Cards;
};

class GenericPlayer : public Hand
{
  friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

public:
  GenericPlayer(const std::string& name = "");
  virtual ~GenericPlayer();
  virtual bool IsHitting() const = 0;
  bool IsBusted() const;
  void Bust() const;
protected:
  std::string m_Name;
};

class Player : public GenericPlayer
{
public:
  Player(const std::string& name = "");
  virtual ~Player();
  virtual bool IsHitting() const;
  void Win() const;
  void Lose() const;
  void Push() const;
};



class House : public GenericPlayer
{
  public:
    House(const std::string& name = "Крупье");
    virtual ~House();
    virtual bool IsHitting() const;
    void FlipFirstCard();
};


#endif // PROTOTYPE_H
