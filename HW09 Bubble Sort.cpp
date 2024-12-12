// Semi Kim
// ITP 165, 2024 spring
// Homework 09 Bubble Sort

#include <iostream>

// Function to dynamically allocate an array
// Parameters: size of array
// Returns: pointer to array
int* makeArray(int size)
{
  int* array = new int[size];
  for (int i = 0; i < size; i++)
    {
      array[i] = rand() % 100;
    }
  return array;
}

// Function to print the array
// Parameters: pointer to array, size of array
// Returns: none
void printArray(int* myArray, int size)
{
  for (int i = 0; i < size; i++)
    {
      std::cout << myArray[i] << "\n";
    }
}

// Function to swap two int with reference parameters
// Parameters: two ints
// Returns: none
void swap(int& a, int& b)
{
  int c = a;
  a = b;
  b = c;
}

// Function to check if each item should be swapped with the next one
// Parameters: pointer to array, size of array
// Returns: whether there were any swaps
bool onePass(int array[], int size)
{
  // Loop through the array
  bool swapped = false;
  for (int i = 0; i < size - 1; ++i)
  {
    // If the element is greater than the next element, swap them
    // and set swapped to true
    if (array[i] > array[i + 1])
    {
      swap(array[i], array[i + 1]);
      swapped = true;
    }
  }
  return swapped;
}

// Funtion to sort the array
// Parameters: pointer to array, size of array
// Returns: none
void bubbleSort(int array[], int size)
{
  // Loop until no swaps are made
  bool swapped = true;
  while (swapped)
  {
    swapped = onePass(array, size); // update swapped
  }
}

int main() {
  std::cout << "How many numbers do you want? ";
  int size;
  std::cin >> size;
  int* myArray = makeArray(size);
  
  std::cout << "The unsorted array:\n";
  printArray(myArray, size);
  
  std::cout << "The sorted array:\n";
  bubbleSort(myArray, size);
  printArray(myArray, size);
  delete[] myArray;
}