#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student
{
private:
  std::string username;
  std::string password;
  std::string fullName;
  int projectGrade;
  int quizGrade;
  int midtermGrade;
  int finalGrade;

public:

  std::string getStudentUsername();

  std::string getStudentPassword();
  
  std::string getStudentName();

  int getProjectGrade();

  int getQuizGrade();

  int getMidtermGrade();

  int getFinalGrade();

  double getOverallGrade();

  void setStudentUsername(std::string user);

  void setStudentPassword(std::string pass);

  void setFullName(std::string name);

  void setProjectGrade(int grade);

  void setQuizGrade(int grade);

  void setMidtermGrade(int grade);

  void setFinalGrade(int grade);
};
#endif
