// Semi Kim
// ITP 165, 2024 spring
// Homework 11 Roster

#include "student.h"
#include <iostream>
#include <fstream>

// The function accepts a const std::string& and an int by reference as input
// It returns a Student pointer which has an array of students created on the heap
Student* loadStudents(const std::string& fileName, int& numStudent)
{
  std::ifstream file(fileName);

  // Read the number of students from the file
  file >> numStudent;
  file.ignore();  // Ignore newline character

  // Create an array of Student objects on the heap
  Student* students = new Student[numStudent];

  // Load data for each student
  for (int i = 0; i < numStudent; ++i) {
    students[i].load(file);
  }

  file.close();

  return students;
}

int main() {
  int numStudents = 0;
  Student* students = loadStudents("short.txt", numStudents);

  // Print information for each student
  for (int i = 0; i < numStudents; ++i)
  {
    std::string result = students[i].toString();
    std::cout << result << std::endl;
  }

  // Cleanup
  delete[] students;

  return 0;
}