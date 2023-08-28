#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>  
#include <cstdio>
#include <vector>
#include "student.h"
#include "instructor.h"

using namespace std;

string Instructor::getInstructorUsername()
{
  return username;
}

string Instructor::getInstructorPassword()
{
  return password;
}

string Instructor::getInstructorName()
{
  return fullName;
}

Student getStudent(string username, vector<Student> &v)
{
  Student user;
  for (size_t i = 0; i < v.size(); i ++)
    {
      if (v[i].getStudentName().compare(username) == 0)
	{
	  user = v[i];
	  break;
	}
    }
  return user;
}

Student getMinStudent(int gradeType, vector<Student> &v)
{
  int min = 100;
  Student minStudent = v[0];
  switch (gradeType)
    {
    case (1):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  if (v[i].getProjectGrade() < min)
	    {
	      min = v[i].getProjectGrade();
	      minStudent = v[i];
	    }
	}
      break;
    case (2):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  if (v[i].getQuizGrade() < min)
	    {
	      min = v[i].getQuizGrade();
	      minStudent = v[i];
	    }
	}
      break;
    case (3):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  if (v[i].getMidtermGrade() < min)
	    {
	      min = v[i].getMidtermGrade();
	      minStudent = v[i];
	    }
	}
      break;
    case (4):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  if (v[i].getFinalGrade() < min)
	    {
	      min = v[i].getFinalGrade();
	      minStudent = v[i];
	    }
	}
      break;
    case(5):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  if (v[i].getOverallGrade() < min)
	    {
	      min = v[i].getOverallGrade();
	      minStudent = v[i];
	    }
	}
      break;
    }
  return minStudent;
}

Student getMaxStudent(int gradeType, vector<Student> &v)
{
  int max = 0;
  Student maxStudent = v[0];
  switch (gradeType)
    {
    case (1):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  if (v[i].getProjectGrade() > max)
	    {
	      max = v[i].getProjectGrade();
	      maxStudent = v[i];
	    }
	}
      break;
    case (2):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  if (v[i].getQuizGrade() > max)
	    {
	      max = v[i].getQuizGrade();
	      maxStudent = v[i];
	    }
	}
      break;
    case (3):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  if (v[i].getMidtermGrade() > max)
	    {
	      max = v[i].getMidtermGrade();
	      maxStudent = v[i];
	    }
	}
      break;
    case (4):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  if (v[i].getFinalGrade() > max)
	    {
	      max = v[i].getFinalGrade();
	      maxStudent = v[i];
	    }
	}
      break;
    case(5):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  if (v[i].getOverallGrade() > max)
	    {
	      max = v[i].getOverallGrade();
	      maxStudent = v[i];
	    }
	}
      break;
    }
  return maxStudent;
}

double getAvg(int gradeType, vector<Student> &v)
{
  double avg = 0;
  switch (gradeType)
    {
    case (1):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  avg += v[i].getProjectGrade();
	}
      break;
    case (2):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  avg += v[i].getQuizGrade();
	}
      break;
    case (3):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  avg += v[i].getMidtermGrade();
	}
      break;
    case (4):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  avg += v[i].getFinalGrade();
	}
      break;
    case (5):
      for (size_t i = 0; i < v.size(); i ++)
	{
	  avg += v[i].getOverallGrade();
	}
      break;
    }
  return avg/(double)v.size();
}

void Instructor::setInstructorUsername(string user)
{
  username = user;
}

void Instructor::setInstructorPassword(string pass)
{
  password = pass;
}
  
void Instructor::setInstructorName(string name)
{
  fullName = name;
}


