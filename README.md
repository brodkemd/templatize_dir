This shell script provides the functionality to create new directory by using another one as a template.

# Install instructions:
   
   1) Update that apt repository:
   
      sudo apt update && sudo apt upgrade

   2) Must install the following package:
      
      sudo apt install rename

   3) Clone this repository:
   
      git clone "https://github.com/brodkemd/templatize_dir"

   4) Run the config file to add the command to the bash alias config file (.bash_aliases) and adds the install location to the shell script
      
      ./config

# How to use this command:
   Method 1:
      
      format:template TYPE NAME

         CURRENT TYPE OPTIONS ARE (you can add some, see next section):
           C++
           qiskit

         NAME: whatever you want to call the new project

   Method 2:
      
      Format: template TEMPLATE_DIRECTORY PROJECT_DIRECTORY FLAG NAME"

         TEMPLATE_DIRECTORY: this option is where you specify the path to the directory that you want to use as a template for the project.
         NOTE: do not add a / at the end of the path please otherwise it will not work as intended

         PROJECT_DIRECTORY: this option is where you specify the directory where you want the project directory to be placed, if a path is provided where the
         directories do not exist they will be made no matter their position on the hierachy.
         NOTE: a drectory will be made in this directory with the name of the project.
         NOTE: do not add a / at the end of the path it will mess things up.

         FLAG: this option is the string that you want to replace in project, including in directory names, file names, and file contents

         NAME: this option is the string that represents what you want to call the project it will replace flag in the project directory, including in directory 
         names, file names, and file contents 


# To set a new directory as a template:

   Follow the format below and your result to the templatize.sh file at line 35, NOTE: add a space after 
   double semi-colon so that is a space between you added code and the next case.

      TYPE)
         to_find=FLAG

         # /$2 exists so that the script makes a directory with the name for the project that was passed in, it was passed second
         working_dir=PROJECT_DIRECTORY/$2

         template_dir=TEMPLATE_DIRECTORY
         ;;

      Definitions for Above terms:
      TYPE: what you want to call this collection of parameters.
      FLAG: The string that gets replaced in the directory names, file names, and file contents.
      PROJECT_DIRECTORY: Where you want the directory that is made for the project to be placed. It is follow by /$2 because the second passed in the script is the 
      name for the project so the /$2 makes the directory with the name of the project.
      TEMPLATE_DIRECTORY: Path to the template for project directory
    

   Example of a template that I use
      
      c++)
      # setting the string that needs to be replaced
      to_find=template_cpp

      # directory where the project will be placed
      working_dir=~/Documents/C++/$2

      # setting the path to the template for the new project
      template_dir=~/Documents/Shell/templatize_dir/template_cpp
      ;;
