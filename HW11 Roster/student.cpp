#include "student.h"
#include <fstream>

// Constructor
Student::Student(std::string name, int labNum, int* labScores, int hwNum, int hwTotalPoint, int* hwScores, int midtermScore, int finalScore)
{
  mName = name; 
  mLabNum = labNum;
  mLabScores = new int[labNum];
  for (int i = 0; i < labNum; i++)
    {
      mLabScores[i] = labScores[i];
    }
  mHwNum = hwNum;
  mHwTotalPoint = hwTotalPoint;
  mHwScores = new int[hwNum];
  for (int i = 0; i < hwNum; i++)
    {
      mHwScores[i] = hwScores[i];
    }
  mMidtermScore = midtermScore;
  mFinalScore = finalScore;
}

// Destructor
Student::~Student()
{
  delete[] mLabScores;
  delete[] mHwScores;
}

// The function will generate a formatted std::string suitable for displaying to the user
std::string Student::toString()
{
  std::string result = "Name: " + mName + "\n\t\t" + "Labs: ";
  for (int i = 0; i < mLabNum - 1; i++)
    {
      result += std::to_string(mLabScores[i]) + ", ";
    }
  result += std::to_string(mLabScores[mLabNum - 1]);
  
  result += "\n\t\tHomework: ";
  for (int i = 0; i < mHwNum - 1; i++)
    {
      result += std::to_string(mHwScores[i]) + ", ";
    }
  result += std::to_string(mHwScores[mHwNum - 1]);
  
  result += "\n\t\tMidterm: " + std::to_string(mMidtermScore) + "\n\t\tFinal: " + std::to_string(mFinalScore);
  
  float labGrade = getLabGrade();
  float hwGrade = getHomeworkGrade();
  float overallGrade = getOverallGrade();
  result += "\n\t\tLab %: " + std::to_string(labGrade) + "\n\t\tHomework %: " + std::to_string(hwGrade) + "\nOverall %: " + std::to_string(overallGrade);
  
  return result;
}

// The function accepts a const std::string& as input and returns nothing
void Student::setName(const std::string& name)
{
  mName = name;
}

// The function accepts an int as input and returns nothing
void Student::setMidterm(int& midtermScore)
{
  mMidtermScore = midtermScore;
}

// The function accepts an int as input and returns nothing
void Student::setFinal(int& finalScore)
{
  mFinalScore = finalScore;
}

// The function accepts an int and a const int* as input and returns nothing
void Student::setLabs(int& labNum, const int* labScores)
{
  mLabNum = labNum;
  mLabScores = new int[labNum];  // dynamically allocate
  for (int i = 0; i < labNum; i++)
    {
      mLabScores[i] = labScores[i];
    }
}

// The function accepts 2 ints and a const int* as input and returns nothing
void Student::setHomework(int& hwNum, int& hwTotalPoint, const int* hwScores)
{
  mHwNum = hwNum;
  mHwTotalPoint = hwTotalPoint;
  mHwScores = new int[hwNum];
  for (int i = 0; i < hwNum; i++)
    {
      mHwScores[i] = hwScores[i];
    }
}

// The function accepts no input and returns a float with the requested data
float Student::getLabGrade()
{
  float labTotal = 0.0f;
  for (int i = 0; i < mLabNum; i++)
    {
      labTotal += (float)mLabScores[i];  // cast int to float
    }
  float labGrade = labTotal / mLabNum * 100;
  return labGrade;
}

// The function accepts no input and returns a float with the requested data
float Student::getHomeworkGrade()
{
  float hwTotal = 0.0f;
  for (int i = 0; i < mHwNum; i++)
    {
      hwTotal += (float)mHwScores[i];
    }
  float hwGrade = hwTotal / mHwTotalPoint * 100;
  return hwGrade;
}

// The function accepts no input and returns a float with the requested data
float Student::getOverallGrade()
{
  float labGrade = getLabGrade();
  float hwGrade = getHomeworkGrade();
  float overallGrade = (labGrade * 0.2) + (hwGrade * 0.4) + (mMidtermScore * 0.2) + (mFinalScore * 0.2);
  return overallGrade;
}


void Student::load(std::ifstream& file)
{
  // Read student's name
  std::getline(file, mName);

  file >> mLabNum;
  file.ignore();
  
  mLabScores = new int[mLabNum];
  for (int i = 0; i < mLabNum; ++i) {
      file >> mLabScores[i];
  }

  file >> mHwNum >> mHwTotalPoint;
  file.ignore();
  mHwScores = new int[mHwNum];
  for (int i = 0; i < mHwNum; ++i) {
      file >> mHwScores[i];
  }

  file >> mMidtermScore >> mFinalScore;

  file.ignore();
}