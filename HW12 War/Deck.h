// Semi Kim
// ITP 165, 2024 spring
// Homework 12 War

#pragma once
#include "Card.h"
#include <string>
#include <vector>

class Deck {
private:
  std::vector<Card> mCards;
public:
  void fill();
  void shuffle();
  void print() const;
  Card takeTop();
  void addBottom(const Card& card);
  int getCount() const;
};