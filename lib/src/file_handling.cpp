#include "../lib.h"

/*
** inputs: a string that represents a name of file
** outputs: NONE
** Decription: prints "Error opening: FILE_NAME" to terminal
*/
void lib::opening_error(std::string file_name){
    std::cout << "Error opening: " << file_name << std::endl;
}

/*
** inputs: a vector of strings that the lines of the file will be copied into, a string that represents the name of file you want the lines from 
** outputs: since the vector is passed by reference the vector is the output, NOTE: the vector is cleared when it is passed
** Decription: copies the lines of the file with the passed in name into the vector, accepts absolute path
*/
void lib::copy_lines_of_file_to_vector(std::vector<std::string>& lines, std::string file_name_or_path){

    // clearing the inputted vector
    lines.clear();

    // letting use know what is happening
    //lib::print("Copying lines from: " + file_name_or_path);

    std::ifstream read;
    
    // opening the inputted file name
    read.open(file_name_or_path);

    // empty variable to copy lines of the file into
    std::string line;

    // checking that the file is open
    if (read.is_open()){

        // while there is a line read it
        while(std::getline(read, line)){
        
            // append the line to the end of the inputted vector
            lines.push_back(line);

        }
    }
    else{
        // if the file fails to open inform the user and stop the program
        opening_error(file_name_or_path);
    }
    
    // closing the file
    read.close();
}

/*
** inputs: a vector of strings that each of element represents a line that will be written to the file, a string that represents the name of file
** you want the lines to be written to 
** outputs: the elements of the vector are written to the output file
** Decription: writes the contents of the vector to the file with the inputted name, NOTE: the lines of the file are erased, accepts absolute path
*/
void lib::write_lines_of_vector_to_file(std::vector<std::string> lines, std::string file_name_or_path){

    // informing the user what is happening
    //lib::print("writing lines to file: " + file_name_or_path);

    std::ofstream write;

    // opening the file
    write.open(file_name_or_path);

    // making sure the file open
    if(write.is_open()){
        // iterates through the elements of the vector and appends a \n to end the line, then writes the line to file
        for(std::string line : lines){
            line += "\n";
            write << line;
        }
    }
    else{
        // if the file fails to open inform the user and stop the program
        opening_error(file_name_or_path);
    }

    // closing the file
    write.close();

}

            
/*
** inputs: a string that represents the line that will be written to the file, a string that represents the name of file
** you want the lines to be written to 
** outputs: the string is written to the output file
** Decription: writes a string to the file with the inputted name, NOTE: the lines of the file are erased, accepts absolute path
*/
void lib::write_line_to_file(std::string line, std::string file_name_or_path){

    // informing the user what is happening
    lib::print("writing lines to file: " + file_name_or_path);

    std::ofstream write;

    // opening the file
    write.open(file_name_or_path);

    // making sure the file open
    if(write.is_open()){
        // writes the line to file
        write << line;

    }
    else{
        // if the file fails to open inform the user and stop the program
        opening_error(file_name_or_path);
    }

    // closing the file
    write.close();
}


/*
** inputs: a string that represents the name of the file to pull the lines from, a string that represents the name of the file to write the lines
** of the other file too
** outputs: a file with the lines of the other file, NOTE: the vector is cleared when it is passed
** Decription: copies the lines of the first file passed in to the second file passed in, accepts absolute path
*/
void lib::copy_lines_from_one_file_to_another(std::string source_file_name, std::string destination_file_name){
    // empty vectors to store the lines from each file
    std::vector<std::string> lines_in_source_file;

    // copies lines of the source file to its corresponding vector
    lib::copy_lines_of_file_to_vector(lines_in_source_file, source_file_name);

    // writes the lines of the source file to the destination file
    lib::write_lines_of_vector_to_file(lines_in_source_file, destination_file_name);

}

/*
** inputs: a string that represents the name of the directory to pull the files from, a string that represents the name of the directory to files into
** of the other file too
** outputs: a directory with the contents of the other directory in it
** Decription: copies the contents of the first directory passed in to the second directory passed in, accepts absolute path
*/
void lib::copy_contents_from_one_directory_to_another(std::string source_directory_name_or_path, std::string destination_directory_name_or_path){

    //string that holds the commands to be excuted by the kernal
    std::string copy_command;

    // adding command, moves to source directory
    copy_command = "cd " + source_directory_name_or_path + "; ";

    // adding command, partial of the copy command
    copy_command += "cp * ";
    
    // determines if a path was provided, if not it adds .. which gives a relative path for the copy command
    // determines this by essentially checking to see if there is a / before directory name
    if ((lib::first(destination_directory_name_or_path, '/') == destination_directory_name_or_path.length() - 1) || (lib::first(destination_directory_name_or_path, '/') == -1)){
        // adding the ../ to the beginning of destination directory variable
        destination_directory_name_or_path.insert(0, "../");
    }

    // adding rest of copy command
    copy_command += destination_directory_name_or_path;

    lib::print("this is the copy command: " + copy_command);

    // running the copy command
    lib::run_command(copy_command);

}

/*
** inputs: a vector of strings where each element represents the a name of the file you want to make
** outputs: makes the files that you passed in
** Decription: makes files with the names listed in the passed in vector, accepts absolute path
*/
void lib::make_these_files(std::vector<std::string> files_to_make){

    // string that stores the names of the files along with the bash command
    std::string make_command = "touch ";
    make_command += lib::vector_to_string(files_to_make, true);

    // running the make command
    lib::run_command(make_command);
}

/*
** inputs: a string that represents the name of the file that you want to make
** outputs: a new file with the name that you passed in
** Decription: makes a file with the passed in name, accepts absolute path
*/
void lib::make_these_files(std::string files_to_make){

    // string that stores the names of the files along with the bash command
    std::string make_command = "touch ";
    make_command += files_to_make;

    // running the make command
    lib::run_command(make_command);
}

/*
** inputs: a vector of strings where each element represents the a name of the file you want to remove
** outputs: removes the files that you passed in
** Decription: removes files with the names listed in the passed in vector, accepts absolute path
*/
void lib::remove_these_files(std::vector<std::string> files_to_remove){

    // string that stores the names of the files along with the bash command
    std::string remove_command = "rm " + lib::vector_to_string(files_to_remove, true);

    // running the remove command
    lib::run_command(remove_command);
}

/*
** inputs: a string that represents the name of the file that you want to remove
** outputs: a removed file
** Decription: removes a file with the passed in name, accepts absolute path
*/
void lib::remove_these_files(std::string files_to_remove){

    // string that stores the names of the files along with the bash command
    std::string remove_command = "rm " + files_to_remove;

    // running the remove command
    lib::run_command(remove_command);
}

/*
** inputs: a vector of strings where each element represents the a name of the directory you want to make
** outputs: makes the directories that you passed in
** Decription: makes directories with the names listed in the passed in vector, accepts absolute path
*/
void lib::make_these_directories(std::vector<std::string> directories_to_make){

    // string that stores the names of the files along with the bash command
    std::string make_command = "mkdir " + lib::vector_to_string(directories_to_make, true);

    // running the make command
    lib::run_command(make_command);
}

/*
** inputs: a string that represents the name of the directory that you want to make
** outputs: a new directory with the name that you passed in
** Decription: makes a directory with the passed in name, accepts absolute path
*/
void lib::make_these_directories(std::string directories_to_make){

    // string that stores the names of the files along with the bash command
    std::string make_command = "mkdir " + directories_to_make;

    // running the make command
    lib::run_command(make_command);
}

/*
** inputs: a vector of strings where each element represents the a name of the directory you want to remove
** outputs: removes the directories that you passed in
** Decription: removes directories with the names listed in the passed in vector, accepts absolute path
*/
void lib::remove_these_directories(std::vector<std::string> directories_to_remove){

    // string that stores the names of the files along with the bash command
    std::string remove_command = "rm -r " + lib::vector_to_string(directories_to_remove, true);

    // running the remove command
    lib::run_command(remove_command);
}

/*
** inputs: a string that represents the name of the directory that you want to remove
** outputs: a removed directory
** Decription: removes a directory with the passed in name, accepts absolute path
*/
void lib::remove_these_directories(std::string directories_to_remove){

    // string that stores the names of the files along with the bash command
    std::string remove_command = "rm -r " + directories_to_remove;

    // running the remove command
    lib::run_command(remove_command);
}

// not used
/*
// copies the file from the absolute path to the directory of the executing code, returns the the file name
std::string lib::copy_file_to_cur_dir_to_open (std::string absolute_path) {
    // instance of library
    lib inst;

    // empty string to write the file name to
    std::string file_name;

    // checks to make sure the file does not exist in the current directory by looking for the / in the file name
    if (lib::first(absolute_path, '/') != -1){

        // declaring neccessary string to be added to the vector
        std::string command = "cp ";
        
        // adding the path of the file to the string
        command += absolute_path;

        // adding a neccessary item to the string
        command += " `pwd`";

        // running the string in terminal
        lib::run_command(command);

        // finds last index of / to deternmine the file name
        int pos = lib::last(absolute_path, '/');

        // finding the name of the file from the path
        file_name = absolute_path.substr(pos + 1, absolute_path.length() - (pos + 1));


    }
    // if the file is not in the directory of the executable
    else {
        // do not need to do anything to the provided string
        file_name = absolute_path;

    }

    // returning the file name
    return file_name;
}

// copies the file back to the directory that it came from
void lib::copy_file_back_to_original_directory (std::string absolute_path) {
    // instance of library
    lib inst;
    
    // finds last index of / to deternmine the file name
    int pos = lib::last(absolute_path, '/');

    // finding the name of the file from the path
    std::string file_name = absolute_path.substr(pos + 1, absolute_path.length() - (pos + 1));

    // erasing the path part from the provided path
    absolute_path.erase(absolute_path.begin() + pos, absolute_path.end());

    // adding needed items to a string
    std::vector<std::string> input;

    // declaring neccessary string to be added to the vector
    std::string command = "cp ";

    // adding the path of the file to the string
    command += file_name;

    // adding a space
    command += " ";

    // adding a neccessary item to the string
    command += absolute_path;

    // adding ; to seperate commands
    command += "; ";

    // adds line to the input vector that removes file from the current directory
    command += "rm " + file_name;

    // running the command in terminal
    lib::run_command(command);


}
*/
