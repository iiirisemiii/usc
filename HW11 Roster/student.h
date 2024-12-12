#pragma once
#include <string>

// Create a Student Class
class Student
{
private:
  std::string mName;
  int mLabNum;
  int* mLabScores;
  int mHwNum;
  int mHwTotalPoint;
  int* mHwScores;
  int mMidtermScore;
  int mFinalScore;
public:
  // Declare default constructor
  Student() : mName(""), mLabNum(0), mLabScores(nullptr), mHwNum(0), mHwTotalPoint(0), mHwScores(nullptr), mMidtermScore(0), mFinalScore(0) {}
  // Declare constructor
  Student(std::string name, int labNum, int* labScores, int hwNum, int hwTotalPoint, int* hwScores, int midtermScore, int finalScore);
  // Declare destructor
  ~Student();

  std::string toString();
  void setName(const std::string& name);
  void setMidterm(int& midtermScore);
  void setFinal(int& finalScore);
  void setLabs(int& labNum, const int* labScores);
  void setHomework(int& hwNum, int& hwTotalPoint, const int* hwScores);
  float getLabGrade();
  float getHomeworkGrade();
  float getOverallGrade();
  void load(std::ifstream& file);
};