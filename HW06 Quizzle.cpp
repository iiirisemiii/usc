// Semi Kim
// ITP 165, 2024 spring
// Homework 06 Quzzle

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Function to read the contents of a file into a vector of strings
void readData(const std::string& filename, std::vector<std::string>& questions, std::vector<std::string>& answers)
{
    // Open the file for reading
    std::ifstream file(filename);
  
    if (!file.is_open())
    {
        std::cout << "Error: Unable to open file " << filename << "\n";
    }
    else
    {
        // Read the contents of the file into the vectors
        std::string question;
        std::string answer;
        while (std::getline(file, question, ',') && std::getline(file, answer))
        {
            questions.push_back(question);
            answers.push_back(answer);
        }
        file.close();
    }
}

void swap(std::string& a, std::string& b)
{
  std::string c = a;
  a = b;
  b = c;
}

// Function to shuffle the order of the questions and answers
void shuffle(std::vector<std::string>& questions, std::vector<std::string>& answers)
{
    int j = questions.size();
    int i = 0;
    for (j = questions.size(); j > 1; j--)
      {
        i = rand() % j;
        swap(questions[i], questions[j - 1]);
        swap(answers[i], answers[j - 1]);
      }  
}

int main()
{
    std::string filename;
    std::cout << "Welcome to Quizzle\n";
    std::cout << "Enter filename of quiz data: ";
    std::cin >> filename;

    if (filename == "StateCapitals.txt")
    {
      std::cout << "Questions are state and answers are capital.\n";
    }

    else if (filename == "Elements.txt")
    {
      std::cout << "Questions are number and answers are element.\n";
    }

    // Declare a vector of questions and a vector of answers
    std::vector<std::string> questions;
    std::vector<std::string> answers;
  
    char quizAgain = 'y';
    while (quizAgain == 'y' || quizAgain == 'Y')
    {
        // Read the data from the file and then shuffle the data
        readData(filename, questions, answers);
        shuffle(questions, answers);
      
        int correctCount = 0;

        // Repeat (with a newly selected 5 questions) until the user wants to stop.
        for (int i = 0; i < 5; ++i)
        {
            std::string userAnswer;
            std::cout << questions[i] << "? ";
            std::cin >> userAnswer;

            if (userAnswer == answers[i])
            {
                std::cout << "correct!\n";
                correctCount++;
            }
            else
            {
                std::cout << "oops, correct answer is " << answers[i] << ".\n";
            }
        }

        std::cout << "You got " << correctCount << " correct.\n";
        std::cout << "Quiz again? (y/n): ";
        std::cin >> quizAgain;
    }

    std::cout << "kthxbye\n";

    return 0;
}
