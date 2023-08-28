#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <string>
#include <vector>
#include "student.h"

class Instructor
{
private:
  std::string username;
  std::string password;
  std::string fullName;
  
public:
  
  std::string getInstructorUsername();

  std::string getInstructorPassword();
  
  std::string getInstructorName();

  void setInstructorUsername(std::string user);

  void setInstructorPassword(std::string pass);

  void setInstructorName(std::string fullName);
};

Student getStudent(std::string username);

Student getMinStudent(int gradeType, std::vector<Student> &v);

Student getMaxStudent(int gradeType, std::vector<Student> &v);

double getAvg(int gradeType, std::vector<Student> &v);

#endif
