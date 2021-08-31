#include "../lib.h"

/*
** inputs: a string
** outputs: NONE
** Decription: Prints the inputted string to the terminal
*/
void lib::print(std::string in) {
    std::cout << in << std::endl;
}

/*
** inputs: a string
** outputs: NONE
** Decription: Prints the inputted string to the terminal
*/
void lib::print(char in) {
    std::cout << in << std::endl;
}

/*
** inputs: an int
** outputs: NONE
** Decription: Prints the inputted string to the terminal
*/      
void lib::print(int in) {
    std::cout << in << std::endl;
}

/*
** inputs: a double
** outputs: NONE
** Decription: Prints the inputted double to the terminal
*/     
void lib::print(double in) {
    std::cout << in << std::endl;
}
/*
** inputs: a long int
** outputs: NONE
** Decription: Prints the inputted long int to the terminal
*/
void lib::print(long in) {
    std::cout << in << std::endl;
}

/*
** inputs: a vector of strings
** outputs: NONE
** Decription: Prints each element of the vector to the terminal
*/
void lib::print(std::vector<std::string> in) {
    for (std::string it : in) {
        std::cout << "\t" << it << std::endl;
    }
}

/*
** inputs: a vector of doubles
** outputs: NONE
** Decription: Prints each element of the vector to the terminal
*/
void lib::print(std::vector<double> in) {
    for (double it : in) {
        std::cout << it << std::endl;
    }
}

/*
** inputs: a vector of ints
** outputs: NONE
** Decription: Prints each element of the vector to the terminal
*/
void lib::print(std::vector<int> in) {
    for (int it : in) {
        std::cout << it << std::endl;
    }
}

/*
** inputs: a vector of chars
** outputs: NONE
** Decription: Prints each element of the vector to the terminal
*/
void lib::print(std::vector<char> in) {
    for (char it : in) {
        std::cout << it << std::endl;
    }
}

/*
** inputs: a 2-D vector of doubles
** outputs: NONE
** Decription: Prints each element of the 2-D vector to the terminal, with  a row number before each row
** i.e. Row 0: contents of row
*/
void lib::print(std::vector<std::vector<double>> in){
    for(int i = 0; i < in.size(); i++){
        std::cout << "Row " << i << ":\t";
        for(double j : in[i]){
            std::cout << j << "\t";
        }
        std::cout << std::endl;
    }
}

/*
** inputs: a 2-D vector of strings
** outputs: NONE
** Decription: Prints each element of the 2-D vector to the terminal, with  a row number before each row
** i.e. Row 0: contents of row
*/
void lib::print(std::vector<std::vector<std::string>> in){
    for(int i = 0; i < in.size(); i++){
        std::cout << "Row " << i << ":\t";
        for(std::string j : in[i]){
            std::cout << j << "\t";
        }
        std::cout << std::endl;
    }
}

/*
** inputs: a 2-D vector of ints
** outputs: NONE
** Decription: Prints each element of the 2-D vector to the terminal, with  a row number before each row
** i.e. Row 0: contents of row
*/
void lib::print(std::vector<std::vector<int>> in){
    for(int i = 0; i < in.size(); i++){
        std::cout << "Row " << i << ":\t";
        for(int j : in[i]){
            std::cout << j << "\t";
        }
        std::cout << std::endl;
    }
}
