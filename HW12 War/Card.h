// Semi Kim
// ITP 165, 2024 spring
// Homework 12 War

#pragma once
#include <string>

class Card {
public:
  enum VALUE {
             TWO,
             THREE,
             FOUR,
             FIVE,
             SIX,
             SEVEN,
             EIGHT,
             NINE,
             TEN,
             JACK,
             QUEEN,
             KING,
             ACE,
  VALUE_TOTAL
  };
  enum SUIT {
             CLUB,
             DIAMOND,
             HEART,
             SPADE,
  SUIT_TOTAL
  };

  VALUE value;
  SUIT suit;

  Card(VALUE value, SUIT suit);

  std::string getString() const;
};