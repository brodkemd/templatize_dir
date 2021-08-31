config: config.o Library/lib.o Library/searching.o Library/prints.o Library/file_handling.o
	g++ -o config config.o Library/lib.o Library/searching.o Library/prints.o Library/file_handling.o

config.o: config.cpp
	g++ -c config.cpp

clean:
	rm *.o config