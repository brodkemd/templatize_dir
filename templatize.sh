# function that displays info on the command
function invalid_inputs () {
        echo "format:template <TYPE> <NAME>"
        echo "TYPE options are:"
        echo "C++"
        echo "Q"
        echo "NAME: whatever you want to call the new project"
        echo "Alternate format: template <TEMPLATE_DIRECTORY> <PROJECT_DIRECTORY> <FLAG> <NAME>"
        # exits the script
        exit 0
}
if [ ${#2} -eq 0 ]
then
    echo ""
    echo "must enter a name"
    echo ""
    invalid_inputs
    exit

elif [ $# -eq 2 ]
then
    # determines what type of project the user wants and makes it
    case $1 in

        help)
            invalid_inputs
            ;;

        C++)
            # setting the string that needs to be changed
            to_find=template_cpp

            # project directory
            working_dir=~/Documents/C++/$2

            # setting where the template is
            template_dir=~/Documents/Shell/templatize_dir/template_cpp
            ;;
        
        Q)
            # setting the string that needs to be changed
            to_find=template_Q

            # project directory
            working_dir=/Documents/Qcode/$2

            # setting where the template is
            template_dir=~/Documents/Shell/templatize_dir/template_Q
            ;;

        *)
            # if they enter something that is wrong let them know
            invalid_inputs
    esac

    # setting the string that replaces the one that is found to the name that was passed in
    replacement=$2

elif [ $# -eq 4 ]
then
    template_dir=$1

    working_dir=$2/$4

    to_find=$3

    replacement=$4

else
    invalid_inputs

fi

# making the project directory, -p will make everything in path if need be 
mkdir -p $working_dir

#copying the template there
cp $template_dir/* $working_dir

# initializing variable
dirs_temp="initialized"

# initializing empty arrary that stores the directories that have already been copied
existing_dirs=()

#initializing variable
last_dir="initialized"

# initializing a directory to be used for comparisions
pwd_compare="hello"

# essentially a boolean
check_result=0

# initialize the max count that a loop can complete based on the size of the list being
# iterated through
max_count=0

#boolean indicating that it iterated through all possibilities the last time as well
move_on=0

# used in assigning temporary but important information
temp_var="hello"

# debugging iteration limiter
#limit=10
#counter_for_limit=0

#going to the directory
cd $working_dir

# changing all occurences of the string in every file in the directory, there are there to account for case
# changing it to the name that was passed in
find ./ -type f | xargs sed -i  's/'"$to_find"'/'"$replacement"'/g'
find ./ -type f | xargs sed -i  's/'"${to_find^}"'/'"${replacement^}"'/g'
find ./ -type f | xargs sed -i  's/'"${to_find^^}"'/'"${replacement^^}"'/g'

# counts how many iterations the loop lower in this file will go through
# used for comparison
function max_iterations () {

    # erases the count from previous calls of this function, so it doesn't keep compounding
    max_count=0

    # iterating through the list of subdirectories in this directory
    for i in $dirs_temp
    do
        # counting the entries
        (( max_count+=1 ))
    done
}

# checks if a directory has already been investigated
function check_if_already_exists () {
    #echo "comparing the present working directory: input ="$pwd_compare

    # iterates through each element in the list
    for element in ${existing_dirs[@]}
    do
        #echo "element being compared: "$element

        #checks if the option for a subdirectory in the list or not
        if [ $element = $pwd_compare ]
        then
            # if so then indicates that it already exists, essentially a boolean "true" value
            check_result=1

            #exits the function
            return

        # if the element if the parent directory where this begins 
        elif [ $element = $working_dir ]
        then
            
            # indicates that it is the parent directory 
            check_result=2

            # exits function
            return
        fi
    done

    # if it does not exist, essentially a boolean "false" value
    check_result=0

    #echo "check function is returning:"$check_result

    #exiting the function
    return
}

function exe() {
    # renaming all of the files and directories
    echo "running the rename function"
    rename 's/'"$to_find"'/'"$replacement"'/' *
    rename 's/'"${to_find^}"'/'"${replacement^}"'/' *
    rename 's/'"${to_find^^}"'/'"${replacement^^}"'/' *
}

# the main function of the this file, moves around the directories and copies the files
function move_dirs () {

    #indicating where this script is
    echo ""
    echo "Current location:"`pwd`

    # iteration counter for the for loop
    local counter=0

    local exit="false"

    # list of all the subdirectories in this directory=
    dirs_temp=`ls -d */`

    # counts how many iterations there will be if the loop goes through all iterations
    # used to indicate when to move up a directory
    max_iterations

    #echo "What is being iterated through:" $dirs_temp

    # iterates through all the directories in the list
    for temp_dir in $dirs_temp
    do
        # incrementing the iteration counter
        (( counter+=1 ))
        
        #echo "moving to: " $temp_dir
        
        # setting a variable to pwd for future comparison
        pwd_compare=`pwd`

        # compares the length of the two strings to see if they are in the same directory
        # if pwd_compare is shorter then it is a higher directory
        if [ ${#pwd_compare} -lt ${#working_dir} ]
        then 
            # informing the user
            echo "current directory is higher on the directory tree: exiting"
            
            # exits the script
            exit
        fi

        #echo "Current directory is lower on the tree: as expected"

        # editing the variable to include the needed "/" that denotes a lower directory
        pwd_compare+='/'

        # editing the variable to include the name of the subdirectory
        pwd_compare+=$temp_dir

        # checks if the subdirectory already exists or not
        check_if_already_exists

        # if the subdirectory does not already exist
        if [ $check_result -eq 0 ]
        then
            #informing the user
            echo $pwd_compare "directory has not been investigated yet: moving there now"

            #moving into the directory that has not been copied yet
            cd $pwd_compare

            # recursion call
            move_dirs
        fi

    done

    #echo "iterations of the for loop=" $counter "; Max =" $max_count

    # essentially if the list had 0 elements, so there are no more subdirectories
    if [ $counter -eq 0 ]
    then
        #informing the user
        echo "reached end of branch: copying then moving up one"
        
        #assigning the a value to the temp variable because it is the most reliable
        temp_var=`pwd`

        #appending the subdirectory indicator to the string
        temp_var+='/'

        # adding the string which is the directory that has had its contents fully copied
        existing_dirs+=($temp_var)
        
        # running the exe function
        exe

        # moving up a directory
        cd ..

    # if the loop iterated all the way through the list and did the last time of execution, more explanation later
    # this is due to the script already going through the subdirectories
    elif [ $max_count -eq $counter ] && [ $move_on -eq 1 ]
    then
        # informing the user
        echo "exhausted all branches in this directory: moving up one now"

        #assigning the a value to the temp variable because it is the most reliable
        temp_var=`pwd`

        #appending the subdirectory indicator to the string
        temp_var+='/'

        # adding the string which is the directory that has had its contents fully copied
        existing_dirs+=($temp_var)

        # running the exe function
        exe

        # moving up a directory
        cd ..

    # if the loop iterated all the way through the list and did not the last time of execution
    # needs the addition information about the last execution otherwise it would not copy the 
    # contents of the last directory
    elif [ $max_count -eq $counter ]
    then
        # setting what is essentially a boolean to indicate it iterated all the way throught the list for
        # the first time
        move_on=1

        # informing the user
        echo "reached end of branch: copying then moving up one"
        
        #assigning the a value to the temp variable because it is the most reliable
        temp_var=`pwd`

        #appending the subdirectory indicator to the string
        temp_var+='/'

        # adding the string which is the directory that has had its contents fully copied
        existing_dirs+=($temp_var)
        
        # running the exe function
        exe
        
        # moving up a directory
        cd ..
    fi

    # used in debugging to limit the number of recursions the function can do
    # the following if statement is as well
    #echo "counter= " $counter_for_limit
    #(( counter_for_limit+=1 ))

    #if [ $counter_for_limit -ge $limit ]
    #then
     #   return
    #else
    
    # informing the user
    echo "running self again"

    # adding space so the recursions are easy to follow
    echo " "

    # recursion call
    move_dirs
    
    #fi
}

# calling the main funtion 
move_dirs