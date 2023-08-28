#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <stdio.h>  
#include <cstdio>
#include <vector>
#include "student.h"
#include "instructor.h"

using namespace std;

/*This is the prompt used whenever the assignment instructions state to "ask login options again".*/
int prompt()
{
  int userType = 0;
  while (userType < 1 || userType > 3)
    {
      cout << "\nUser types,\n\t1 - Instructor\n\t2 - Student\nSelect a login user type or enter 3 to exit: ";
      cin >> userType;
      switch (userType)
	{
	case (1):
	  break;
	case (2):
	  break;
	case (3):
	  break;
	default:
	  cout << "\nInvalid option. Please enter a valid option." << endl;
	}
    }
  return userType;
}

int main(int argc, char *argv[])
{

  /*Checking for only two .txt files given*/
  if (argc != 3)
    {
      cout << "\nPlease give an instructor file and a student file respectively." << endl;
      return EXIT_FAILURE;
    }
  /*Checking for only two files named "instructors.txt" and "students.txt"*/
  if (strcmp(argv[1], "instructors.txt") != 0 || strcmp(argv[2], "students.txt") != 0)
    {
      cout << "\nPlease give an instructor file named 'instructors.txt' and a student file named 'students.txt'" << endl;
      return EXIT_FAILURE;
    }

  /*Initializing these two vectors to be used for creating instructor and student objects for use throughout the program.*/
  vector<Instructor> instructors;
  vector<Student> students;

  ifstream txtFile;
  string strTemp;

  /*This will open the first file argument, which should be the instructor file as detailed in the README, and fill the instructors vector with
    instructor objects will all of their variables having given values according to the .txt file.*/ 
  txtFile.open(argv[1]);
  while (getline(txtFile, strTemp))
    {
      Instructor instructor;
      stringstream ss(strTemp);
      string temp;
      string temp2;
      ss >> temp;
      instructor.setInstructorUsername(temp);
      ss >> temp;
      instructor.setInstructorPassword(temp);
      ss >> temp;
      ss >> temp2;
      instructor.setInstructorName(temp + " " + temp2);
      instructors.push_back(instructor);
    }
  txtFile.close();

  /*This does the same as above but for the students vector.*/
  txtFile.open(argv[2]);
  while(getline(txtFile, strTemp))
    {
      Student student;
      stringstream ss(strTemp);
      string temp;
      string temp2;
      int num;
      ss >> temp;
      student.setStudentUsername(temp);
      ss >> temp;
      student.setStudentPassword(temp);
      ss >> temp;
      ss >> temp2;
      student.setFullName(temp + " " + temp2);
      ss >> num;
      student.setProjectGrade(num);
      ss >> num;
      student.setQuizGrade(num);
      ss >> num;
      student.setMidtermGrade(num);
      ss >> num;
      student.setFinalGrade(num);
      students.push_back(student);
    }
  txtFile.close();
  

  /*This is the main part of the code that displays all the text and choices for the program. Essentially it is the user I/O portion of the code.*/
  int running = 1;
  while (running)
    {
      int choice = prompt();
      /*Choice 1 will open the menu path towards the instructor portion of the program.*/
      if (choice == 1)
	{
	  string username;
	  string password;
	  cout << "\nEnter credentials to login,\n\tEnter username: ";
	  cin >> username;
	  cout << "\tEnter password: ";
	  cin >> password;
	  int success = 0;
	  for (size_t i = 0; i < instructors.size(); i ++)
	    {
	      if (instructors[i].getInstructorUsername().compare(username) == 0 && instructors[i].getInstructorPassword().compare(password) == 0)
		{
		  cout << "\nYou are now logged in as instructor " << instructors[i].getInstructorName() << "." << endl;
		  success = 1;
		}
	    }
	  if (success == 0)
	    {
	      cout << "\nLogin as instructor failed." << endl;
	    }
	  /*If the instructor successfully logged in, more options will be given to the user. If not, they will be notified the login has failed and will be brought back
	    to the initial login prompt.*/
	  else
	    {
	      int queryOption = 0;
	      /*If the user enters 1, they will be given the option to view the grades of a singular student, or that stats for the whole class.*/
	      while(queryOption < 1 || queryOption > 2)
		{
		  cout << "\nQuery options,\n\t1 - View grades of a student\n\t2 - View stats\nEnter option number: ";
		  cin >> queryOption;
		  switch (queryOption)
		    {
		    case (1):
		      {
			/*This will search for a student based on the user-given student username to look for. If it finds them, it will print out their grades. If not, an error prompt
			  will be given and the user will be prompted the query opptions again.*/
			int foundStudent = 0;
			while(foundStudent == 0)
			  {
			    cout << "\nEnter student username to view grades: ";
			    string sun;
			    cin >> sun;
			    for (size_t i = 0; i < students.size(); i ++)
			      {
				if (students[i].getStudentUsername().compare(sun) == 0)
				  {
				    cout<<"\nStudent name: "<<students[i].getStudentName()<<"\n\tProject\t"<<students[i].getProjectGrade()<<"%\n\tQuiz\t"<<students[i].getQuizGrade()<<"%\n\tMidterm\t"<<students[i].getMidtermGrade()<<"%\n\tFinal\t"<<students[i].getFinalGrade()<<"%\n\tOverall\t"<<students[i].getOverallGrade()<<"%"<<endl;
				    foundStudent = 1;
				    break;
				  }
			      }
			    if (foundStudent == 0)
			      {
				cout << "\nStudent username is not valid." << endl;
			      }
			  }
		      }
		      break;
		      /*This long segment of code details the option to display the stats of the whole class. The user will be asked for an integer 1-5, referring to the
			type of grade they wish to see, and will then print out the correlating grades of that type. Afterword the user will be brought nack to the
			intial login prompt.*/
		    case (2):
		      {
			int gradeType;
			while (gradeType < 1 || gradeType > 5)
			  {
			    cout<<"\nGrade types,\n\t1 - Project grade\n\t2 - Quiz grade\n\t3 - Midterm grade\n\t4 - Final grade\n\t5 - Overall grade\nSelect a grade type to view stats: ";
			    cin >> gradeType;
			    switch (gradeType)
			      {
			      case (1):
				{
				  Student pgmin = getMinStudent(1, students);
				  Student pgmax = getMaxStudent(1, students);
				  cout<<"\nProject Grade stats,\n\tmin\t"<<pgmin.getProjectGrade()<<"% ("<<pgmin.getStudentName()<<")\n\tmax\t"<<pgmax.getProjectGrade()<<"% ("<<pgmax.getStudentName()<<")\n\tavg\t"<<getAvg(1, students)<<"%"<<endl;
				}
				break;
			      case (2):
				{
				  Student qgmin = getMinStudent(2, students);
				  Student qgmax = getMaxStudent(2, students);
				  cout<<"\nQuiz Grade stats,\n\tmin\t"<<qgmin.getQuizGrade()<<"% ("<<qgmin.getStudentName()<<")\n\tmax\t"<<qgmax.getQuizGrade()<<"% ("<<qgmax.getStudentName()<<")\n\tavg\t"<<getAvg(2, students)<<"%"<<endl;
				}
				break;
			      case (3):
				{
				  Student mtmin = getMinStudent(3, students);
				  Student mtmax = getMaxStudent(3, students);
				  cout<<"\nMidterm Grade stats,\n\tmin\t"<<mtmin.getMidtermGrade()<<"% ("<<mtmin.getStudentName()<<")\n\tmax\t"<<mtmax.getMidtermGrade()<<"% ("<<mtmax.getStudentName()<<")\n\tavg\t"<<getAvg(3, students)<<"%"<<endl;
				}
				break;
			      case (4):
				{
				  Student fgmin = getMinStudent(4, students);
				  Student fgmax = getMaxStudent(4, students);
				  cout<<"\nFinal Grade stats,\n\tmin\t"<<fgmin.getFinalGrade()<<"% ("<<fgmin.getStudentName()<<")\n\tmax\t"<<fgmax.getFinalGrade()<<"% ("<<fgmax.getStudentName()<<")\n\tavg\t"<<getAvg(4, students)<<"%"<<endl;
				}
				break;
			      case (5):
				{
				  Student ogmin = getMinStudent(5, students);
				  Student ogmax = getMaxStudent(5, students);
				  cout<<"\nOverall Grade stats,\n\tmin\t"<<ogmin.getOverallGrade()<<"% ("<<ogmin.getStudentName()<<")\n\tmax\t"<<ogmax.getOverallGrade()<<"% ("<<ogmax.getStudentName()<<")\n\tavg\t"<<getAvg(5, students)<<"%"<<endl;
				}
				break;
			      default:
				cout << "\nInvalid option. Please enter a valid option." << endl;
			      }
			  }
		      }
		      break;
		    default:
		      cout << "\nInvalid option. Please enter a valid option." << endl;
		    }
		}
	    }
	}
      /*Choice 2 will open the menu path towards the student portion of the program.*/
      if (choice == 2)
	{
	  /*The same login format as the instructor option.*/
	  string username;
	  string password;
	  Student currentStu;
	  cout << "\nEnter credentials to login,\n\tEnter username: ";
	  cin >> username;
	  cout << "\tEnter password: ";
	  cin >> password;
	  int success = 0;
	  for (size_t i = 0; i < students.size(); i ++)
	    {
	      if (students[i].getStudentUsername().compare(username) == 0 && students[i].getStudentPassword().compare(password) == 0)
		{
		  cout << "\nYou are now logged in as student " << students[i].getStudentName() << "." << endl;
		  currentStu = students[i];
		  success = 1;
		  break;
		}
	    }
	  if (success == 0)
	    {
	      cout << "\nLogin as student failed." << endl;
	    }
	  /*Takes the set student and asks the user if they want to view the grades of that student, displaying it if the user enters "y", and returning to the
	    login prompt if the user enters anything else.*/
	  else
	    {
	      string view = "";
	      cout << "\nDo you want to view grades (y/n)? ";
	      cin >> view;
	      if (view.compare("y") == 0)
		{
		  cout<<"\nStudent name: "<<currentStu.getStudentName()<<"\n\tProject\t"<<currentStu.getProjectGrade()<<"%\n\tQuiz\t"<<currentStu.getQuizGrade()<<"%\n\tMidterm\t"<<currentStu.getMidtermGrade()<<"%\n\tFinal\t"<<currentStu.getFinalGrade()<<"%\n\tOverall\t"<<currentStu.getOverallGrade()<<"%"<<endl;
		}
	    }
	}
      /*Choice 3 exits the program.*/
      if (choice == 3)
	{
	  return EXIT_SUCCESS;
	}
    }
  return EXIT_SUCCESS;
}
