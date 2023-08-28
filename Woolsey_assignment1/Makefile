main: main.o instructor.o student.o
	g++ -g -Wall -o main main.o instructor.o student.o

main.o: main.cpp instructor.h student.h
	g++ -c -Wall main.cpp

instructor.o: instructor.cpp instructor.h student.h
	g++ -c -Wall instructor.cpp

student.o: student.cpp
	g++ -c -Wall student.cpp

clean:
	rm -f *.o main
