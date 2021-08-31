#include "../lib.h"

/*
** inputs: a string and a char
** outputs: an int that represents an index in the string
** Decription: searches through a string and returns the index of the first occurence of a char in a string
*/
int lib::first(std::string line, char x) {
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == x) {
            return i;
        }
    }
    return -1;
}


/*
** inputs: a vector of strings and a string
** outputs: an int that represents an index in the vector of strings
** Decription: searches through a vector and returns the index of the first row in the list that equals the inputted string
*/
int lib::first(std::vector<std::string> vars, std::string op) {
    for (int j = 0; j < vars.size(); j++) {
        if (vars[j] == op) {
            return j;
        }
    }
    return -1;
}

/*
** inputs: a vector of ints and an int
** outputs: an int that represents an index in the vector of ints
** Decription: searches through a vector and returns the index of the first row in the list that equals the inputted int
*/ 
int lib::first(std::vector<int> stor, int x) {
    for (int y = 0; y < stor.size(); y ++) {
        if (stor[y] == x) {
            return y;
        }
    }
    return -1;
}

/*
** inputs: a vector of doubles and a double
** outputs: an int that represents an index in the vector of doubles
** Decription: searches through a vector and returns the index of the first row in the list that equals the inputted double
*/ 
int lib::first(std::vector<double> stor, double x) {
    for (int y = 0; y < stor.size(); y ++) {
        if (stor[y] == x) {
            return y;
        }
    }
    return -1;
}

/*
** inputs: a string and a string
** outputs: an int that represents an index in the string named line
** Decription: searches through a string and returns the index of the beginning of the first string that equals the inputted string named x
*/
int lib::first(std::string line, std::string x) {
    if (x.length() <= line.length()){
        for (int i = 0; i < line.length() - x.length(); i++) {
            if (line.substr(i, x.length()) == x) {
                return i;
            }
        }
    }
    return -1;
}

/*
** inputs: a string and a string
** outputs: an int that represents an index in the string named line
** Decription: searches through a string and returns the index of the beginning of the last string that equals the inputted string named x
*/
int lib::last(std::string line, std::string x) {
    int pos = -1;
    if (x.length() <= line.length()){
        for (int i = 0; i < (line.length() - x.length()); i++) {
            if (line.substr(i, x.length()) == x) {
                pos = i;
            }
        }
    }
    return pos;
}

/*
** inputs: a string and a char
** outputs: an int that represents an index in the string named line
** Decription: searches through a string and returns the index of the last char that equals the inputted char named x
*/
int lib::last(std::string line, char x) {
    int pos = -1;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == x) {
            pos = i;
        }
    }
    return pos;
}

/*
** inputs: a string and a string
** outputs: NONE
** Decription: the inputted string named to_match_case contains the desired cases for its chars and the string named to_change_case has
** the cases of its chars changed to match that of the string name to_match_case 
** Note: This function will only capitalize all of the chars or the first one currently
*/  
void lib::match_case_of_strings(std::string to_match_case, std::string& to_change_case){

    // finds the index of the first letter in to_match_case
    int position_of_first_letter_in_to_match_case = lib::find_first_letter_in_string(to_match_case);
    
    // finds the index of the first letter in to_change_case
    int position_of_first_letter_in_to_change_case = lib::find_first_letter_in_string(to_change_case);
    
    // varible that holds how many uppercase letters there are in the to_match_case string
    int count = 0;

    // iterates through the to_match_case string starting at the position of the first letter
    for (int i = position_of_first_letter_in_to_match_case; i < to_match_case.length(); i++){
        // if the char in the string it upper case
        if (lib::determine_case_of_char(to_match_case[i]) == 2) {
            count++;
        }

        // if there are two upper case letters in the string then the for loop is exiteds
        if (count == 2){
            break;
        }
    }
    switch (count)
    {
    case 0:
        // if there were no upper case letters in the to_match_case string, then the to_change_case string
        // is converted to all lower case
        lib::to_lower(to_change_case);
        break;
    
    case 1:
        // if there was one upper case letters in the to_match_case string, then the first letter in the 
        // to_change_case to converted to upper case
        lib::to_upper(to_change_case[position_of_first_letter_in_to_change_case]);
        break;
    
    case 2:
        // if there was more than one upper case letter in the to_match_case string, all of the letters in
        // to_change_case are converted to upper case
        lib::to_upper(to_change_case);
        break;

    }
}


/*
** inputs: a string
** outputs: an int 
** Decription: returns an int that represents index of the first letter in a string
*/
int lib::find_first_letter_in_string (std::string line){

    int i = 0;
    // while the char in the string is not a member of the upper or lower case alphabet the int is incremented
    while (lib::first(lib::upper_alphabet, line[i]) == -1 && lib::first(lib::lower_alphabet, line[i]) == -1){
        i++;
    }

    return i;
}



/*
** inputs in order: a vector of strings, a string that is what you want to find in the vector, a string that you will replace what you find with,
** a bool that indicates if case matter matters or not (true if it does matter), a bool that indicates if you want the replacement string
** to match the case of the string that it found, and an int that indicates what you the replacement string to replace (0 if you want the replacement string
** to replace beginning of element in the vector up to the found string, 1 if you want to replace everything after the found string in the element of the vector,
** 2 if you want to replace the found string in the element of the vector)
** outputs: NONE
** Decription: replaces the instance of the string named to_find in every string in the vector with the string named replacement in the previously lsited
** ways, case can be ignored or matched be the string being replaced and the string that is the replacement
*/
// searches for a string in a vector of strings and replaces it with what you want it to, it can replace everything before
// the string, everything after the string, or replace the string itself 
// options: before = 0, after = 1, on = 2
void lib::search_for_and_replace_string_in_vector_with_options(std::vector<std::string>& lines, 
                                                            std::string to_find, 
                                                            std::string replacement,
                                                            bool ignore_case,
                                                            bool match_case, 
                                                            int how_to_replace){
    
    // temporary variable to store substrings of an element of the inputted vector
    std::string line_before_change, temp;

    if (match_case){
        ignore_case = true;
    }
    
    /*
    if (ignore_case){
        lib::to_upper(to_find);
    }
    */
    // informing the user what is happening
    //lib::print("searching for replacement");

    // iterates through all the elements of the vector
    for (std::string& line : lines){
        
        /*
        //lib::print("Line in vector: " + line);
        if (ignore_case){
            line_before_change = line;
            lib::to_upper(line);
        }
        */

        // checking to make sure the element is large than what is needs to be found
        if(line.length() >= to_find.length()){
            
            // iterating through the element
            for (int i = 0; i <= ((line.length()) - to_find.length()); i++){
                
                if ((i + to_find.length() - 1) < line.length()){
                    // assigning substring of the line that is the same length as the string that needs to be found
                    temp = line.substr(i, to_find.length());
                }
                else {
                    break;

                }

                if (ignore_case){
                    if (lib::to_upper(temp) != lib::to_upper(to_find)) continue;
                }
                else if(temp != to_find) continue;
                    

                // if the user wants the strings to have matching case
                if (match_case){
                    // calling a function that matches the case of the two strings
                    lib::match_case_of_strings(line.substr(i, to_find.length()), replacement);
                    
                    //lib::print("replacement: " + replacement);

                }
            
                
                // informing the use
                //lib::print("found the string to replace: " + to_find);

                // determining where to put the replacement string depending where the user specified
                switch (how_to_replace)
                {
                // if the replacement string needs to placed after the string that was found
                case 1:
                    // adding neccessary string// inserting the replacement string directly after the string that was found
                    for (int j = 0; j < replacement.length(); j++){
                        line.push_back(replacement[j]);
                    }
                    
                    break;

                // if the replacement string needs to be replaced before the string that was found
                case 0:
                    // informing the use
                    //lib::print("inserting at the beginning");

                    // erasing all characters that come before the string that was found
                    line.erase(line.begin(), line.begin() + i);

                    // inserting the replacement string directly in front of the string that was found
                    for (int j = 0; j < replacement.length(); j++){
                        line.insert(line.begin(), replacement[j]);
                    }
                    
                    break;

                // if the replacement string needs to replace the string that was found
                case 2:
                    // informing the user
                    //lib::print("inserting by replacing");

                    // erasing the string that was found
                    line.erase(line.begin() + i, line.begin() + i + to_find.length());

                    // inserting the replacement string in the found string's place
                    for (int j = 0; j < replacement.length(); j++){
                        line.insert(line.begin() + i + j, replacement[j]);
                    }

                    break;
                }
            }
        }
        // if the element of the vector was not longer than the string that needs to be found, the for loop just increments
        else{
            continue;

        }
    }
}

// do not use this unless neccessary, it is 75 times slower than the one above you
/*
void search(std::string line, std::string to_find){
  if (to_find.length() < line.length()){    
    int middle_r;
    int middle_l;

    if (line.length() % 2 == 0){
      middle_l = line.length() / 2;
      middle_r = (line.length() / 2 - 1);
    }
    else { 
      middle_l = floor(line.length() / 2);
      middle_r = middle_l;
    }

    for (int i = 0; i < ceil(line.length() / 4); i++){
      if (to_find[0] == line[i]) {
        if (line.substr(i, to_find.length()) == to_find){
          std::cout << "got one" << std::endl;;
        }
      }

      if (to_find[0] == line[middle_l - i]){
        if(line.substr(middle_l - i, to_find.length()) == to_find){
          std::cout << "got one" << std::endl;
        }
      }

      if (to_find[0] == line[middle_r + i]){
        if(line.substr(middle_r + i, to_find.length()) == to_find){
          std::cout << "got one" << std::endl;
        }
      }
      if (to_find[to_find.length() - 1] == line[line.length() - 1 - i]){
        if(line.substr(line.length() - 1 - i - (to_find.length() - 1), to_find.length()) == to_find){
          std::cout << "got one" << std::endl;
        }
      }
    }
  }
  else if (to_find.length() == line.length()){
    if (to_find == line){
        std::cout << "got one" << std::endl;
    }
  }

}
*/