// Semi Kim
// ITP 165, 2024 spring
// Homework 12 War

#include <iostream>
#include "Deck.h"

int main() {
  Deck player1;
  Deck player2;
  Deck central;
  player1.fill();
  player1.shuffle();
  player2.fill();
  player2.shuffle();

  int round = 1;
  while (player1.getCount() > 0 && player2.getCount() > 0)
  {
    // Each player places 1 card back into the central Deck
    central.addBottom(player1.takeTop());
    central.addBottom(player2.takeTop());

    Card player1Card = central.takeTop();
    Card player2Card = central.takeTop();

    std::cout << player1.getCount() << " vs " << player2.getCount() << " cards\n";
    std::cout << player1Card.getString() << " vs " << player2Card.getString() << "\n";

    // If it’s a tie, both players place an extra card into the central Deck, and then we loop back to the top
    while (player1Card.value == player2Card.value)
    {
        std::cout << "Tie\n";
        for (int i = 0; i < 2; ++i)
        {
          central.addBottom(player1.takeTop());
          central.addBottom(player2.takeTop());
        }
        player1Card = central.takeTop();
        player2Card = central.takeTop();
        std::cout << player1Card.getString() << " and " << player2Card.getString() << "\n";
    }

    // Whichever player had the higher card takes the entire Deck and adds those cards into their own hand (Deck)
    if (player1Card.value > player2Card.value)
    {
      std::cout << "Player 1 takes 2 cards\n";
      player1.addBottom(player1Card);
      player1.addBottom(player2Card);
    }
    else
    {
      std::cout << "Player 2 takes 2 cards\n";
      player2.addBottom(player1Card);
      player2.addBottom(player2Card);
    }

  round++;
  }

  // Declare the winner
  if (player1.getCount() == 0)
  {
    std::cout << "Player 2 wins in " << round << " rounds\n";
  }
  else
  {
    std::cout << "Player 1 wins in " << round << " rounds\n";
  }

  return 0;
}
