// Semi Kim
// ITP 165, 2024 spring
// Homework 01 Donut

#include <iostream>
#include <iomanip>

int main() {
  std::cout << "Welcome to the bakery.\n";
  
  std::string Name = "Semi";
  std::cout << "What is your name?: ";
  std::cin >> Name;

  int Donut = 0;
  std::cout << "How many donuts would you like?: ";
  std::cin >> Donut;

  int Sprinkles = 0;
  std::cout << "How many with sprinkles?: ";
  std::cin >> Sprinkles;

  float Total = Donut * 2.70 + Sprinkles * 0.35;
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Thank you for your order, " << Name << "! Your " << Donut << " donuts with "<< Sprinkles << " sprinkles cost $" << Total << ".";
  std::cin >> Total;
}