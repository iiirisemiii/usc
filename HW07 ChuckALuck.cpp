// Semi Kim
// ITP 165, 2024 spring
// Homework 07 ChuckALuck

#include <iostream>

// Function: roll
// Purpose: Roll a single die
// Parameters: None
// Returns: the number the user rolled
int roll()
{
  int numberRolled = rand() % 6 + 1;
  return numberRolled;
}

// Function: roll
// Purpose: Fill the inputted array with random numbers from 1 to 6
// Parameters: the dice array; the size of the dice array;
// Returns: Nothing
void roll(int array[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
    {
      array[i] = roll();
    }
}

// Function: displayRoll
// Purpose: Display the results of dice thrown
// Parameters: the dice array; the size of the dice array
// Returns: Nothing
void displayRoll(int array[], int arraySize)
{
  roll(array, arraySize);
  for (int i = 0; i < arraySize; i++)
  {
    std::cout << "\t\t" << array[i] << "\n";
  }
}

// Function: computeBetResult
// Purpose: Determine the user's winnings and return the money won or lost
// Parameters: the dice array; the size of the dice array; the amount of money the user bet; the number the user bet on
// Returns: the money won or lost
int computeBetResult(int array[], int arraySize, int betAmount, int betNumber)
{
  int payout = 0;
  int match = 0;
  // Check if the user's bet number matches any of the dice numbers
  for (int i = 0; i < arraySize; i++)
    {
      if (array[i] == betNumber)
      {
        match ++;
      }
    }
  std::cout << "You matched " << match << " dice!\n";
  payout = betAmount * match;
  if (match == 0)
    {
      std::cout << "You lost your bet :(\n";
    }
  else
  {
    std::cout << "YOU WIN $" << payout << "\n";
  }
  return payout;
}

int main() {
  const int size = 3;
  int money = 100;
  int betAmount = 0;
  int betNumber = 0;
  int payout = 0;
  
  std::cout << "STEP RIGHT UP AND PLAY SOME CHUCK-A-LUCK!\n";
  
  char playAgain = 'y';
  // Loop until the user chooses to stop
  while (playAgain == 'y')
    {
      std::cout << "You now have $" << money <<"\n";
      std::cout << "Enter a bet amount: $";
      std::cin >> betAmount;
      
      // Loop until the user enters a valid bet amount
      while (betAmount > money)
        {
          std::cout << "Invalid bet. Please enter an amount from $0 to " << money;
          std::cout << "Enter a bet amount: $";
          std::cin >> betAmount;
        }
      std::cout << "What number do you want to bet on (1-6)? ";
      std::cin >> betNumber;
      
      // Loop until the user enters a valid bet amount
      while (betNumber < 1 || betNumber > 6)
        {
          std::cout << "Invalid bet. Must be between 1 and 6: ";
          std::cin >> betNumber;
        }
      std::cout << "You bet $" << betAmount << " on " << betNumber << "\n";
      std::cout << "You rolled: \n";
      
      int array[size];
      roll(array, size);
      displayRoll(array, size);
      
      // If the user wins, add the winnings to their money
      payout = computeBetResult(array, size, betAmount, betNumber);
      if (payout > 0)
      {
        money += payout;
      }
      // If the user loses, subtract the bet amount from their money
      else
      {
        money -= betAmount;
      }
      
      std::cout << "You now have $" << money << "\n";
      std::cout << "Would you like to play again? (y/n): ";
      std::cin >> playAgain;
    }

  // If the user chooses not to play again, display their final money
  std::cout << "You ended the game with $" << money;
}