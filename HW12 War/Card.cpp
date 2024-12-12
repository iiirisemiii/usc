// Semi Kim
// ITP 165, 2024 spring
// Homework 12 War

#include "Card.h"

Card::Card(VALUE myvalue, SUIT mysuit)
{
  value = myvalue;
  suit = mysuit;  
}

// return a string that matches the VALUE and SUIT of the Card.
// For example: “Ace of Clubs” or “2 of Diamonds”
std::string Card::getString() const
{
  static const std::string valueStrings[] =
  {
    "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "King", "Queen", "Ace",
  };

  static const std::string suitStrings[] =
  {
    "Clubs", "Diamonds", "Hearts", "Spades",
  };

  return valueStrings[value] + " of " + suitStrings[suit];
}