// Semi Kim
// ITP 165, 2024 spring
// Homework 12 War

#include "Deck.h"
#include "Card.h"
#include <iostream>

void swap(Card& a, Card& b)
{
  Card c = a;
  a = b;
  b = c;
}

// Function: fill
// Purpose: fills the deck with all 52 cards in sorted order
// Parameters: none
// Returns: nothing
void Deck::fill()
{
  for (int suit = 0; suit < Card::SUIT_TOTAL; suit++)
    {
      for (int value = 0; value < Card::VALUE_TOTAL; value++)
        {
          Card card((Card::VALUE)value, (Card::SUIT)suit);
          mCards.push_back(card);
        }
    }
}

// Function: shuffle
// Purpose: randomly shuffles the deck
// Parameters: none
// Returns: nothing
void Deck::shuffle()
{
  int j = mCards.size();
  int i = 0;
  for (j = mCards.size(); j > 1; j--)
    {
      i = rand() % j;
      swap(mCards[i], mCards[j - 1]);
    }
}

// Function: print
// Purpose: prints out the Deck to the console
// Parameters: none
// Returns: nothing
void Deck::print() const
{
  for (int i = 0; i < mCards.size(); i++)
    {
      std::cout << mCards[i].getString() << ",\n";
    }
}


// Function: takeTop
// Purpose: take the top card from the Deck
// this removes 1 card from the deck and returns it to the player
// Parameters: none
// Returns: one Card
Card Deck::takeTop()
{
  Card topCard = mCards[0];

  for (int i = 0; i < mCards.size() - 1; i++)
  {
      mCards[i] = mCards[i + 1];
  }

  mCards.pop_back();

  return topCard;
}

// Function: addBottom
// Purpose: adds 1 card to the end of the Deck
// Parameters: card is the card to add to the Deck
// Returns: nothing
void Deck::addBottom(const Card& card)
{
  mCards.push_back(card);
}

// Function: getCount
// Purpose: tells the user how many Cards there are in the Deck
// Parameters: none
// Returns: the number of Cards left in the Deck
int Deck::getCount() const
{
  return mCards.size();
}