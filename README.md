 <a href="logo github"><img src="https://www.holbertonschool.com/holberton-logo.png" align="middle" width=“409” height=“128”></a>
# PROJECT SIMPLE SHELL

**Introduction**

In this simple shell project, we simulate sh (sh is a shell or command line interpreter for computer operating systems).

**Project information**

The project was developed with the following requirements:

- Editors: `vi`, `emacs`
- The files will be compiled on Ubuntu 14.04 LTS
- C programs and functions will be compiled with `gcc 4.8.4` using the following flags `-Wall -Werror -Wextra -pedantic and -g`. After compiling memcheck is validated: `valgrind --tool=memcheck --leak-check=yes ./hsh`.

**How to run this simulation of sh?**

1. Pull master branch: 

  `git pull https://github.com/jpenariasholberton/simple_shell.git`

2. Compile all C and header files:

  `-Wall -Werror -Wextra -pedantic -g simple_shell.h *.c -o hsh`

**How to test**

1. **Mode interactive:** Run the output file locally to start:

`$ ./hsh`

`$ /bin/ls`

`hsh main.c shell.c`

2. **Mode no-interactive:** You can start typing with a simple command like:

`$ echo "/bin/ls" | ./hsh`

`hsh main.c shell.c test_ls_2`

`$`


**Authors**
- Vanessa Sotomayor 
- Jiseth Peña Arias

