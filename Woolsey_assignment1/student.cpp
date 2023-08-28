#include <string>
#include "student.h"

using namespace std;

string Student::getStudentUsername()
{
  return username;
}

string Student::getStudentPassword()
{
  return password;
}

string Student::getStudentName()
{
  return fullName;
}

int Student::getProjectGrade()
{
  return projectGrade;
}

int Student::getQuizGrade()
{
  return quizGrade;
}

int Student::getMidtermGrade()
{
  return midtermGrade;
}

int Student::getFinalGrade()
{
  return finalGrade;
}

double Student::getOverallGrade()
{
  return (projectGrade * 0.3) + (quizGrade * 0.1) + (midtermGrade * 0.2) + (finalGrade * 0.4);
}

void Student::setStudentUsername(string user)
{
  username = user;
}

void Student::setStudentPassword(string pass)
{
  password = pass;
}

void Student::setFullName(string name)
{
  fullName = name;
}

void Student::setProjectGrade(int grade)
{
  projectGrade = grade;
}

void Student::setQuizGrade(int grade)
{
  quizGrade = grade;
}

void Student::setMidtermGrade(int grade)
{
  midtermGrade = grade;
}

void Student::setFinalGrade(int grade)
{
  finalGrade = grade;
}
