/*файл: definitions.cpp
 *автор: Цыпин Андрей
 *дата: 19.03.2021
 *операционная система: ubuntu
 *задание: 6
 */

#include "prototype.h"

std::ostream& endll(std::ostream& os){ // собственный манипулятор двойного перевода строки
   os.put(os.widen('\n')); // перевод строки
   os.put(os.widen('\n')); // перевод строки
   os.flush(); // принудительная очистка буфера вывода
   return os;
}

Card::Card(rank r, suit s, bool ifUp): m_Rank(r), m_Suit(s), m_IsFaceUp(ifUp){}

int Card::GetValue() const
{
 int value = 0;
 if (m_IsFaceUp)
 {
    value = m_Rank;
    if (value > 10) value = 10;
  }

  return value;
}

void Card::Flip()
{
  m_IsFaceUp = !(m_IsFaceUp);
}
std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
  const std::string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
                           "10", "J", "Q", "K"};

  const std::string SUITS[] = {"c", "d", "h", "s"};

  if (aCard.m_IsFaceUp)
      os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
  else
      os << "XX";

  return os;
}

Hand::Hand()
{
  m_Cards.reserve(7);
}

Hand::~Hand()
{
  Clear();
}

void Hand::Add(Card* pCard)
{
  m_Cards.push_back(pCard);
}

void Hand::Clear()
{
  std::vector <Card*>::iterator iter = m_Cards.begin();
  for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
  {
    delete *iter;
    *iter = 0;
  }
  m_Cards.clear();
}

int Hand::GetTotal() const
{
  if (m_Cards.empty()) return 0;
  if (m_Cards[0]->GetValue() == 0) return 0;
  int total = 0;
  std::vector<Card*>::const_iterator iter;
  for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
  total += (*iter)->GetValue();
  bool containsAce = false;
  for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
  if ((*iter)->GetValue() == Card::ACE)
    containsAce = true;
  if (containsAce && total <= 11)
  {
    total += 10;
  }

  return total;
}

GenericPlayer::GenericPlayer(const std::string& name): m_Name(name) {}

GenericPlayer::~GenericPlayer() {}

bool GenericPlayer::IsBusted() const
{
  return (GetTotal() > 21);
}

void GenericPlayer::Bust() const
{
  std::cout << m_Name << " у Вас перебор.\n";
}

Player::Player(const std::string& name): GenericPlayer(name) {}

Player::~Player() {}

bool Player::IsHitting() const
{
  std::cout << m_Name << ", Вы хотите продолжить играть? (Y/N): ";
  char response;
  std::cin >> response;
  return (response == 'y' || response == 'Y');
}

void Player::Win() const
{
  std::cout << m_Name << " выигрывает.\n";
}

void Player::Lose() const
{
  std::cout << m_Name << " проигрывает.\n";
}

void Player::Push() const
{
  std::cout << m_Name << " ничья.\n";
}

House::House(const std::string& name): GenericPlayer(name) {}

House::~House() {}

bool House::IsHitting() const
{
  return (GetTotal() <= 16);
}

void House::FlipFirstCard()
{
  if (!(m_Cards.empty()))
    m_Cards[0]->Flip();

  else
    std::cout << "Нет карты для переворота!\n";
}
