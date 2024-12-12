// Semi Kim
// ITP 165, 2024 spring
// Homework 05 Pancakes

#include <iostream>
#include <vector>

// swap function
void swap(int& a, int& b)
{
  int c = a;
  a = b;
  b = c;
}

// randomize the stack
void randomizeStack(std::vector<int>& pancakes, int num)
{
  int j = pancakes.size();
  int i = 0;
  for (j = pancakes.size(); j > 1; j--)
    {
      i = rand() % j;
      swap(pancakes[i], pancakes[j - 1]);
    }
}

// print out the pancake stack
void printStack(std::vector<int> pancakes, int num)
{
  for (int i = 0; i < pancakes.size(); i++)
    {
      std::cout << i + 1 << ": ";
      for (int j = 0; j < num - pancakes[i] / 2; j++)
        {
          std::cout << " ";
        }
      for (int j = 0; j < pancakes[i]; j++)
        {
          std::cout << "X";
        }
      std::cout << "\n";
    }
}

// flip the pancake
void flip(std::vector<int>& pancakes, int index)
{
    for (int i = 0; i < index / 2; i++)
      {
        int temp = pancakes[i];
        pancakes[i] = pancakes[index - i - 1];
        pancakes[index - i - 1] = temp;
      }
}

// check if the pancake stack is in order
bool isSorted(std::vector<int>& pancakes, int num)
{
  // return true if it's sorted or false if it's not
  bool sorted = true;
  for (int i = 0; i < num; i++)
    {
      if (pancakes[i] != (i + 1) * 2)
      {
        sorted = false;
      }
    }
  return sorted;
}

int main() {
  int num;
  std::cout << "Welcome to Pancake Flipping.\nHow many pancakes do you want? (2-20): ";
  std::cin >> num;
  int counter = 1;
  int point = 0;
  int mode = 2;
  bool sorted;

  // loop until the user wants to quit
  while (mode != 0)
    {
      // mode 2: start an old game
      if (mode == 2)
      {
        // create a vector of pancakes
        std::vector<int> pancakes(num);
        {
          for (int i = 0; i < num; i++)
            {
              pancakes[i] = (i + 1) * 2;
            }
        }

        // randomize the stack -> print out the stack
        randomizeStack(pancakes, num);
        printStack(pancakes, num);

        bool sorted = isSorted(pancakes, num);
        
        // loop until the pancake is sorted
        while (!sorted)
          {
            // ask the user a flip point
            std::cout << "Flip point (" << counter << ")? ";
            std::cin >> point;
            flip(pancakes, point);
            printStack(pancakes, num);
            counter++;
            sorted = isSorted(pancakes, num); // Check if the stack is sorted
          }

        // print out the result if it is sorted
        if (sorted)
        {
          std::cout << "Solved in " << counter - 1 << " moves.\n";
          counter = 1; // reset the counter
          std::cout << "0=quit, 1=new game, 2=old game: ";
          std::cin >> mode;
        }
      }

      // mode 1: start a new game
      if (mode == 1)
      {
        std::cout << "How many pancakes do you want? (2-20): ";
        std::cin >> num;
        int counter = 1;
        int point = 0;

        // create a vector of pancakes
        std::vector<int> pancakes(num);
        {
          for (int i = 0; i < num; i++)
            {
              pancakes[i] = (i + 1) * 2;
            }
        }

        // randomize the stack -> print out the stack
        randomizeStack(pancakes, num);
        printStack(pancakes, num);

        sorted = isSorted(pancakes, num);

        // loop until the pancake is sorted
        while (!sorted)
          {
            // ask the user a flip point
            std::cout << "Flip point (" << counter << ")? ";
            std::cin >> point;
            flip(pancakes, point);
            printStack(pancakes, num);
            counter++;
            sorted = isSorted(pancakes, num); // check if the stack is sorted
          }

        // print out the result if it is sorted
        if (sorted)
        {
          std::cout << "Solved in " << counter - 1 << " moves.\n";
          counter = 1; // reset the counter
          std::cout << "0=quit, 1=new game, 2=old game: ";
          std::cin >> mode;
        }
      }

  if (mode == 0)
    {
      std::cout << "kthnxbye";
    }
  }
}