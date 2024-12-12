// Semi Kim
// ITP 165, 2024 spring
// Homework 04 Numbo

#include <iostream>
#include <vector>
#include <cstdlib>

// create a function for converting a number into a string
std::string num2str(int n) {
  std::string s = "";
  char c;
  for (int i = 0; i < 4; i++) {
    c = '0' + n % 10;
    s = c + s;
    n /= 10;
  }
  return s;
}

// create a function for counting # of hits
int hits(std::string target, std::string guess) {
  int hitsCount = 0;
  for (int i = 0; i < 4; i++)
  {
    if (target[i] != guess[i])
    {
      for (char targetNum : target)
      {
        if (guess[i] == targetNum)
        {
          hitsCount++;
          break;
        }
      }
    }
  }
  return hitsCount;
}

// create a function for counting # of bulls
int bulls(std::string target, std::string guess) {
  int bullsCount = 0;
  for (int i = 0; i < 4; i++) {
    if (target[i] == guess[i]) {
      bullsCount++;
    }
  }
  return bullsCount;
}

// create a function of candidates list -> a new shorter list
// go through the list and get a new shorter list of still good ones
std::vector<std::string> candidateFunction(std::vector<std::string> candidates, std::string guess, int hitsCount, int bullsCount)
{
  std::vector<std::string> candidatesList;
  for (int i = 0; i < candidates.size(); i++)
    {
      int hitsNum = hits(guess, candidates[i]);
      int bullsNum = bulls(guess, candidates[i]);
      if (hitsNum <= hitsCount && bullsNum <= bullsCount)
        {
          candidatesList.push_back(candidates[i]);
        }
    }
  return candidatesList;
}

int main() {
  int mode = -1;
  std::cout << "Welcome to Numbo!\n";
  std::cout << "1=you guess, 2=computer guesses, 0=quit : ";

  // loop while user doesn't quit
  while (mode !=0) {
    std::cout << "1=you guess, 2=computer guesses, 0=quit : ";
    std::cin >> mode;
  
  // use 'if - else if' statments to determine the mode
  // mode 1: computer teaser
  if (mode == 1) {
    int targetNum = 1234;
    std::string targetStr = num2str(targetNum);
    int guessNum = -1;
    int hitsCount = 0;
    int bullsCount = 0;
    int i = 0;
    int counter = 0;
    // use while loop to keep guessing
    while (i < 12)
    {
      std::cout << "Enter a guess (4 digits number): ";
      std::cin >> guessNum;
      std::string guessStr = num2str(guessNum);
      hitsCount = hits(targetStr, guessStr);
      bullsCount = bulls(targetStr, guessStr);
      std::cout << "hits=" << hitsCount << " bulls=" << bullsCount << "\n";
      counter++;
      if (guessStr == targetStr)
      {
        std::cout << "You got it in " << counter << " tries!\n";
        break;
      }
    }
  }
    
  // mode 2: computer guesser
  else if (mode == 2)
  {
    std::cout << "Think of a 4 digit code for me to try to guess.\n... hit ENTER when you have it ...\n";
    // create a vector of possible candidates
    std::vector<std::string> possibilities;
    // use for loop to add all possible numbers to the vector
    for (int i = 0; i < 10000; i++)
      {
        possibilities.push_back(num2str(i));
      }
    
    int counter = 0;
    int hitsCount = 0;
    int bullsCount = 0;
    int guessNum = -1;
    guessNum = rand() % 10000; // initial guess
    std::string guessStr = num2str(guessNum);
    std::cout << "I guess " << guessStr << ".\n";

    std::cout << "hits= ";
    std::cin >> hitsCount;
    std::cout << "bulls= ";
    std::cin >> bullsCount;
    possibilities = candidateFunction(possibilities, guessStr, hitsCount, bullsCount);
    // use for loop to keep guessing
    int i = 0;
    while (i < 12)
      {
          guessStr = possibilities[rand() % possibilities.size()];
          std::cout << "I guess " << guessStr << "\n";
          counter++;
          std::cout << "hits= ";
          std::cin >> hitsCount;
          std::cout << "bulls= ";
          std::cin >> bullsCount;
          possibilities = candidateFunction(possibilities, guessStr, hitsCount, bullsCount);
          if (hitsCount == 0 && bullsCount == 4)
          {
            std::cout << "I guessed it in " << counter << " tries!\n";
            break;
          }
      }
  }
}
  // mode 0: quit
  if (mode == 0)
  {
    std::cout << "bye";
  }
}
