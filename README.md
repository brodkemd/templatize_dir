This shell script provides the functionality to create new directory by using another one as a template.
This is open source, do whatever you want with any of the code in this repository.

#  A: Install instructions:
   
   1) Update that apt repository:
   
      `sudo apt update && sudo apt upgrade`

   2) Must install the following package:
      
      `sudo apt install rename`

   3) Clone this repository:
   
      `git clone "https://github.com/brodkemd/templatize_dir"`
      
   4) Go into that directory:
      
      `cd templatize_dir`

   5) **If you have a regualr computer:**
         
         Run the config file to add the command to the bash alias config file (.bash_aliases) and adds the install location to the shell script
      
         `./config install`
     
      **if you have an ARM based computer:**
         
         Run the following command that rebuilds the executable for that architecture
         
         `cd lib; make; cd ..; make`
         
         Now you can run the install command
            
         `./config install`
      
   6) This command comes with two types (also called templates) out of the box, go to section B to see how to add one of your very own.


# B: To set a new directory as a template:

   1) Go to the templatize_dir directory, you must be there to do this.
   
   2) Run the config exe as show below. It will prompt you with all the necessary things to setup a new template type (also called template). 
      
      `./config add`
   
   3) Now you have a new template that you can easily call just like with any other type above


# C: How to use this command:
   
   **Note**
      You can see the following information by typing "template" in the terminal. Namely:
      
      template
   
   **Method 1:**
      
      Format:template TYPE NAME

      TYPE: any type that you have made so far, to see what types (also called templates) you currently have. 
         Go to line 34 in templatize.sh, this line begins a case structure, this is indicated by "case". Any 
         word the is followd by a ")" is a type (also called template) that you created and can use. Everything 
         from that word to ";;" are the properties of that template, you can edit these if you want but that 
         might have negative side effects if you set something wrong.

      NAME: whatever you want to call the new project
         
      

   **Method 2:**
      
      Format:template TEMPLATE_DIRECTORY PROJECT_DIRECTORY FLAG NAME

      TEMPLATE_DIRECTORY: this option is where you specify the path to the directory that you want to use as 
                          a template for the project.
                          NOTE: do not add a / at the end of the path please otherwise it will not work as intended

      PROJECT_DIRECTORY: this option is where you specify the directory where you want the project directory to 
                         be placed, if a path is provided where the directories do not exist they will be made 
                         no matter their position on the hierachy.
                         NOTE: a drectory will be made in this directory with the name of the project.
                         NOTE: do not add a / at the end of the path it will mess things up.

      FLAG: this option is the string that you want to replace in project, including in directory names, 
            file names, and file contents

      NAME: this option is the string that represents what you want to call the project it will replace FLAG 
            in the project directory, including in directory names, file names, and file contents 
