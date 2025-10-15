# Build target: main executable
main: main.o address.o date.o
	g++ -g main.o address.o date.o -o main

# Compile main.cpp
main.o: main.cpp address.h date.h
	g++ -c -g main.cpp

# Compile address.cpp
address.o: address.h address.cpp
	g++ -c -g address.cpp

# Compile date.cpp
date.o: date.h date.cpp
	g++ -c -g date.cpp

# Clean up all object files and the executable
clean:
	rm -f *.o
	rm -f main

# Run the program
run: main
	./main

# Open with debugger
debug: main
	gdb ./main