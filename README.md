# Simple Shell
This is a simple shell implementation written in C programming language.
It allows users to interact with the operating system by executing commands and managing processe

### How to use it
In order to use this shell, in a terminal, first run the program:    
`prompt$ ./hsh`  
It wil then display a simple prompt and wait for commands.  
`$ `   
A command will be of the type `$ command`  
This shell can handle two types of commands: builtins and normal program.
##### List of built-ins
Currently the list of built-ins I wrote is:  
* cd [directory]  
Switch to the specified directory (path).
* env  
Displays the environment variable
* exit [exitstatus]  
Exit from the program with exitstatus value. 0 by default.
* getenv NAME  
Return the value of the NAME variable if it is in the environment
* help [command]  
Displays the syntax for the command, or all commands.  
* history  
Displays the last typed user .
* echo [$$] or [$?] or [$PATH]
Return pid and exit statue and PATH.


#### Command
* Basically Every Program in `$PATH`

* It support single word like `ls`

* It handle path `ls /tmp`

* It handle options like `ls -l`

* It handle combinations like `ls -l /var`

* Full path commands like `/bin/ls`

* Full path with options and arugments like `/bin/ls -l /var`

### List of functions and system calls we could use
List of allowed functions and system calls

    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    fork (man 2 fork)
    free (man 3 free)
    fstat (man 2 fstat)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    kill (man 2 kill)
    lstat (man 2 lstat)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (man 2 stat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)
    _exit (man 2 _exit)

## Authors
* Fahad Hassan
* Emmanuel Paul
