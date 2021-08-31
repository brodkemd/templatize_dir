#include "lib/lib.h"

using namespace lib;

int main(int argc, char* argv[]) {
    std::vector<std::string> contents;

    if ( argc == 2){
        // casting to string for comparison
        if ((std::string)argv[1] == "install"){
            // figuring out where the script is installed
            std::string output = run_command_and_get_output("pwd");

            // deletes the newline character
            output.pop_back();
            
            // copying the lines of the main shell script to into a vector
            copy_lines_of_file_to_vector(contents, "templatize.sh");

            // setting the first line of file to the to a variable that holds where the script is located
            contents[0] = "install_dir=" + output;

            // writing the lines back to the main shell file
            write_lines_of_vector_to_file(contents, "templatize.sh");

            // running a command that adds makes the .bash_aliases file and adds the required command to utilize the functionaliy
            // of the main shell script
            run_command("touch ~/.bash_aliases; echo \"alias template=\'bash " + output + "/templatize.sh\'\" >> ~/.bash_aliases");

            // exiting
            return 0;
        }
        else if((std::string)argv[1] == "add"){
            // pulling the necessary information from the user
            std::string template_path, working_path, to_find, type;
            std::cout << "What is the path for the template directory (include the template directory name in the path): "<< std::endl;
            std::cin >> template_path;
            std::cout << std::endl;
            
            std::cout << "What is the path for the directory where the project directory will be made(where do you want the project directory to end up): "<< std::endl;
            std::cin >> working_path;
            std::cout << std::endl;
            
            std::cout << "What is the string that must be replaced in the project directory (the flag to replace): "<< std::endl;
            std::cin >> to_find;
            std::cout << std::endl;
            
            std::cout << "What do you want to call this new type: "<< std::endl;
            std::cin >> type;
            std::cout << std::endl;

            // debugging purposes
            /*
            print("");
            print(template_path);
            print(working_path);
            print(to_find);
            print(type);
            */
            
            // initializing a vector that holds how the new lines for the file in the correct formatting with the inputs
            // from the user filling in the needed information
            std::vector<std::string> new_type = {"", 
                                                "\t\t" + type + ")",
                                                "\t\t\t# setting the string that needs to be changed",
                                                "\t\t\tto_find=" + to_find,
                                                "",
                                                "\t\t\t# project directory",
                                                "\t\t\tworking_dir=" + working_path + "/$2",
                                                "",
                                                "\t\t\t# setting where the template is",
                                                "\t\t\ttemplate_dir=" + template_path,
                                                "\t\t\t;;",
                                                "" };
            
            // gets the lines from the file that needs the lines declared above added to it
            copy_lines_of_file_to_vector(contents, "templatize.sh");

            // what line the file the new lines must be placed
            int place = 35;

            // assigning the lines of the vector above to the corresponding lines in the file
            for (int i = place - 1; i < place + new_type.size(); i++){
                contents[i] = new_type[i - place];
            }

            // writing the adjusted lines back to file
            write_lines_of_vector_to_file(contents, "templatize.sh");
            
           return 0;
        }
    }
    // if the past in argument did not match the accepted one or if too many arguments were pasted in
    print("Error: Invalid inupts");

    return 0;
}