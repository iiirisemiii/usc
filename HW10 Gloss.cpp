// Semi Kim
// ITP 165, 2024 spring
// Homework 09 Gloss

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Define a struct to hold the dictionary information for a word
struct WordInfo {
  std::string word;
  float normalFrequency;
  int count;
  float frequencyRatio;
};

// Create a function to reset the count
void resetCount(std::vector<WordInfo*>& wordsInfo)
{
  for (WordInfo* info : wordsInfo)
  {
    info->count = 0;
  }
}

// Create a function to create and fill the vector
void fillVector(std::vector<WordInfo*>& wordsInfo)
{
  std::ifstream file("dictionary.txt");

  // Read in the word and the normal frequency from the file
  std::string word;
  float normalFrequency;
  while (file >> normalFrequency >> word)
  {
    WordInfo* info = new WordInfo();
    info->normalFrequency = normalFrequency;
    info->word = word;
    // fill in the vector
    wordsInfo.push_back(info);
  }
  file.close();
}

// Create a function to clean a word
std::string cleanWord(const std::string& word)
{
  std::string cleanedWord;

  for (char c : word)
  {
    if (c < 0 || isdigit(c) || ispunct(c))
    {
      return ""; // Return empty string to throw out the word
    }
    else
    {
      // Convert uppercase to lowercase
      cleanedWord += tolower(c);
    }
  }
  return cleanedWord;
}

// Create a function to read in a text file and count the words in it
// Return the number of words read from the file
int readIn(std::string& filename, std::vector<WordInfo*>& wordsInfo)
{
  std::ifstream file(filename);
  while (!file.is_open())
  {
    std::cout << "Unable to open file " << filename << "\n";
    std::cout << "Enter filename to do gloss ('quit' to quit): ";  
    std::cin >> filename;
    file.open(filename);
  }
  
  int totalWords = 0;
  std::string word;
  while (file >> word)
  {
    std::string cleanedWord = cleanWord(word);
    if (!cleanedWord.empty())
    {
      // Check if the word is already in the vector
      for (WordInfo *info : wordsInfo)
      {
        if (info->word == cleanedWord)
        {
          info->count++;
        }
        totalWords++;
      }
    }
  }
  file.close();
  return totalWords;
}

void calculateRatio(std::vector<WordInfo*>& wordsInfo, int totalWords)
{
  for (WordInfo* info : wordsInfo)
  {
    // Calculate frequency
    float frequency = (float)info->count / totalWords;

    // Calculate frequency ratio
    float frequencyRatio = frequency / info->normalFrequency;
    
    info->frequencyRatio = frequencyRatio;
  }
}

// Create a function to find the highest ratio
WordInfo* findMaxRatio(std::vector<WordInfo*>& wordsInfo)
{
  float maxRatio = 0.0f;
  WordInfo* maxWord = nullptr;

  // Find the word with the highest ratio
  for (WordInfo* info : wordsInfo)
  {
    if (info->frequencyRatio > maxRatio)
    {
      maxRatio = info->frequencyRatio;
      maxWord = info;
    }
  }

  // Reset the ratio of the word with the highest ratio
  if (maxWord != nullptr)
  {
    maxWord->frequencyRatio = 0.0f;
  }
  
  return maxWord;
}

// Create a function to delete everything in the vector
void deleteVector(std::vector<WordInfo*>& wordsInfo)
{
  for (WordInfo* info : wordsInfo)
  {
    delete info;
  } 
}
  
int main() {
  // Create a std::vector<> of pointers to the struct
  std::vector<WordInfo*> wordsInfo;

  std::string filename;
  std::cout << "Enter filename to do gloss ('quit' to quit): ";  
  std::cin >> filename;
  
  while (filename != "quit")
  {
    fillVector(wordsInfo);

    int totalWords = readIn(filename, wordsInfo);

    // Calculate frequency and frequency ratio
    calculateRatio(wordsInfo, totalWords);

    // Call the function 25 times
    for (int i = 0; i < 25; i++)
    {
      WordInfo* maxWord = findMaxRatio(wordsInfo);
      if (maxWord != nullptr)
      {
        std::cout << maxWord->word << "\n";
      }
    }
    
    resetCount(wordsInfo);
    deleteVector(wordsInfo);
    wordsInfo.clear();
    
    std::cout << "Enter filename to do gloss ('quit' to quit): ";
    std::cin >> filename;
  }
  
  // If the user enters “quit”, end the program
  std::cout << "kthxbye";
  return 0;
}