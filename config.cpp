#include "Library/lib.h"

using namespace lib;

int main() {

    std::vector<std::string> contents;

    // figuring out where the script is installed
    std::string output = run_command_and_get_output("pwd");
    
    // copying the lines of the main shell script to into a vector
    copy_lines_of_file_to_vector(contents, "templatize.sh");

    // setting the first line of file to the to a variable that holds where the script is located
    contents[0] = "install_dir=" + output;

    // writing the lines back to the main shell file
    write_lines_of_vector_to_file(contents, "templatize.sh");

    // running a command that adds makes the .bash_aliases file and adds the required command to utilize the functionaliy
    // of the main shell script
    run_command("touch ~/.bash_aliases; echo \"alias template=\'bash ~/Documents/Shell/templatize_dir/templatize.sh\'\" >> ~/.bash_aliases");

    return 0;
}