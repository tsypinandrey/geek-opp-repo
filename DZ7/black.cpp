/*файл: black.cpp
 *автор: Цыпин Андрей
 *дата: 22.03.2021
 *операционная система: ubuntu
 *задание: 7
 */

#include "black.h"

Card::Card(rank r, suit s, bool ifUp): m_Rank(r), m_Suit(s), m_IsFaceUp(ifUp){}//

int Card::GetValue() const{//
 int value = 0;
 if (m_IsFaceUp) {
    value = m_Rank;
    if (value > 10) value = 10;
  }
  return value;
}
void Card::Flip(){//
  m_IsFaceUp = !(m_IsFaceUp);
}
Hand::Hand(){//
  m_Cards.reserve(7);
}

Hand::~Hand(){//
  Clear();
}

void Hand::Add(Card* pCard){//
  m_Cards.push_back(pCard);
}

void Hand::Clear(){//
    for (Card* iter: m_Cards) // range-base for loop
    {
      delete iter;
      iter = 0;
    }
  m_Cards.clear();
}

int Hand::GetTotal() const{
  if (m_Cards.empty()) return 0;//
  if (m_Cards[0]->GetValue() == 0) return 0;//
  int total = 0;//
  for (Card* iter: m_Cards) // range-base for loop
  total += iter->GetValue();//
  bool containsAce = false;//
  for (Card* iter: m_Cards) // range-base for loop
  if (iter->GetValue() == Card::ACE)//
      containsAce = true;//
  if (containsAce && total <= 11) {//
  total += 10;
  }
  return total;//
}

GenericPlayer::GenericPlayer(const string& name): m_Name(name) {}//

GenericPlayer::~GenericPlayer() {}//

bool GenericPlayer::IsBusted() const {//
  return (GetTotal() > 21);
}

void GenericPlayer::Bust() const {//
  cout << m_Name << " у Вас перебор.\n";
}

Player::Player(const string& name): GenericPlayer(name) {}//

Player::~Player() {}//

bool Player::IsHitting() const {//
  cout << m_Name << ", Вы хотите продолжить играть? (Y/N): ";
  char response;
  cin >> response;
  return (response == 'y' || response == 'Y');
}

void Player::Win() const {//
  cout << m_Name << " выигрывает.\n";
}

void Player::Lose() const {//
  cout << m_Name << " проигрывает.\n";
}

void Player::Push() const {//
  cout << m_Name << " ничья.\n";
}

House::House(const string& name): GenericPlayer(name) {}//

House::~House() {}//

bool House::IsHitting() const {//
  return (GetTotal() <= 16);
}

void House::FlipFirstCard() {//
  if (!(m_Cards.empty()))
    m_Cards[0]->Flip();

  else
    cout << "Нет карты для переворота!\n";
}

Deck::Deck(){//
  m_Cards.reserve(52);
  Populate();
}

Deck::~Deck() {}//

void Deck::Populate() {//
  Clear();
  for (int s = Card::CLUBS; s <= Card::SPADES; ++s) {
    for (int r = Card::ACE; r <= Card::KING; ++r) {
      Add(new Card(static_cast <Card::rank>(r),static_cast <Card::suit>(s)));
    }
  }
}

void Deck::Shuffle() {//
  random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand) {//
  if (!m_Cards.empty()) {
    aHand.Add(m_Cards.back());
    m_Cards.pop_back();
  }
  else {
    cout << "Out of cards, Unable to deal.\n";
  }
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer) {//
  cout << endl;
  while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting()) {
    Deal(aGenericPlayer);
    cout << aGenericPlayer << endl;
  if (aGenericPlayer.IsBusted())
     aGenericPlayer.Bust();
  }
}

Game::Game(const vector<string>& names){//
  for (string pName: names) // range-base for loop
        m_Players.push_back(Player(pName));
  srand(time(0)); //seed the random number generator
  m_Deck.Populate();
  m_Deck.Shuffle();
}

Game::~Game() {}//

void Game::Play() {
  for (int i = 0; i < 2; ++i) {
    for (Player &pPlayer: m_Players) // range-base for loop
          m_Deck.Deal(pPlayer);
    m_Deck.Deal(m_House);
   }
   m_House.FlipFirstCard();
  for (Player &pPlayer: m_Players) // range-base for loop
      cout << pPlayer << endl;
  cout << m_House << endl;
  for (Player &pPlayer: m_Players) // range-base for loop
         m_Deck.AdditionalCards(pPlayer);
  m_House.FlipFirstCard();
  cout << endl << m_House;
  m_Deck.AdditionalCards(m_House);
  if (m_House.IsBusted())
  {
   for (Player &pPlayer: m_Players) // range-base for loop
       if (!(pPlayer.IsBusted()))
             pPlayer.Win();
  }
  else {
    for (Player &pPlayer: m_Players) // range-base for loop
    if (!(pPlayer.IsBusted()))
    {
        if (pPlayer.GetTotal() > m_House.GetTotal())
            pPlayer.Win();

        else if (pPlayer.GetTotal() < m_House.GetTotal())
            pPlayer.Lose();

        else
            pPlayer.Push();
        }
  }
  for (Player &pPlayer: m_Players) // range-base for loop
        pPlayer.Clear();
  m_House.Clear();
}

ostream& operator<<(ostream& os, const Card& aCard) {
  const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
                           "10", "J", "Q", "K"};
  const string SUITS[] = {"c", "d", "h", "s"};
  if (aCard.m_IsFaceUp)
      os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
  else
      os << "XX";
  return os;
}

ostream& operator <<(ostream& os, const GenericPlayer& aGenericPlayer) {
    os << aGenericPlayer.m_Name << ":\t";
    if (!aGenericPlayer.m_Cards.empty()) {
        for (Card* card: aGenericPlayer.m_Cards) // range-base for loop
             os << *card << "\t";
      if (aGenericPlayer.GetTotal() != 0)
          cout << "(" << aGenericPlayer.GetTotal() << ")";
    }
    else
      os << "<Пусто>";
  return os;
}
