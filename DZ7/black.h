/*файл: black.h
 *автор: Цыпин Андрей
 *дата: 19.03.2021
 *операционная система: ubuntu
 *задание: 7
 */

#pragma once

#include "prototype.h"

using namespace std;

class Card{
public:
  enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
           JACK, QUEEN, KING};
  enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};
  friend ostream& operator<<(ostream& os, const Card& aCard);
  Card(rank r = ACE, suit s = SPADES, bool ifUp = true);
  int GetValue() const;
  void Flip();

private:
  rank m_Rank;
  suit m_Suit;
  bool m_IsFaceUp;
};

class Hand{
public:
  Hand();
  virtual ~Hand();
  void Add(Card* pCard);
  void Clear();
  int GetTotal() const;
protected:
  vector <Card*> m_Cards;
};

class GenericPlayer : public Hand {
  friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
public:
  GenericPlayer(const string& name = "");
  virtual ~GenericPlayer();
  virtual bool IsHitting() const = 0;
  bool IsBusted() const;
  void Bust() const;

protected:
  string m_Name;
};

class Player : public GenericPlayer {
public:
  Player(const string& name = "");

  virtual ~Player();
  virtual bool IsHitting() const;
  void Win() const;
  void Lose() const;
  void Push() const;
};


class House : public GenericPlayer {
  public:
    House(const string& name = "Крупье");
    virtual ~House();
    virtual bool IsHitting() const;
    void FlipFirstCard();
};

class Deck : public Hand {
  public:
    Deck();
    virtual ~Deck();
    void Populate();
    void Shuffle();
    void Deal(Hand& aHand);
    void AdditionalCards(GenericPlayer& aGenericPlayer);
};


class Game {
public:
    Game(const vector<string>& names);
    ~Game();
    void Play();
    friend void Instructions();

private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
};

ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);

