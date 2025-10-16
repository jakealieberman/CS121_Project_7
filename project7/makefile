 Build target: main executable
main: main.o address.o date.o student.o
	g++ -g main.o address.o date.o student.o -o main

# Compile main.cpp
main.o: main.cpp address.h date.h student.h
	g++ -c -g main.cpp

# Compile address.cpp
address.o: address.cpp address.h
	g++ -c -g address.cpp

# Compile date.cpp
date.o: date.cpp date.h
	g++ -c -g date.cpp

# Compile student.cpp
student.o: student.cpp student.h address.h date.h
	g++ -c -g student.cpp

# Clean up all object files and the executable
clean:
	rm -f *.o main