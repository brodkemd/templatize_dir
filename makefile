config: config.o lib/lib.o lib/searching.o lib/prints.o lib/file_handling.o
	g++ -o config config.o lib/lib.o lib/searching.o lib/prints.o lib/file_handling.o

config.o: config.cpp
	g++ -c config.cpp

clean:
	rm *.o config