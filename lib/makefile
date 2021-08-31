run: lib.o file_handling.o prints.o searching.o main.o
	g++ -o run lib.o file_handling.o prints.o searching.o main.o

lib.o: src/lib.cpp
	g++ -c src/lib.cpp

file_handling.o: src/file_handling.cpp
	g++ -c src/file_handling.cpp

prints.o: src/prints.cpp
	g++ -c src/prints.cpp

searching.o: src/searching.cpp
	g++ -c src/searching.cpp

main.o:	main.cpp
	g++ -c main.cpp

clean:
	rm *.o run