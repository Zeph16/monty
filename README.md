# C - Stacks, Queues - LIFO, FIFO


### The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Compilation
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

##### The Monty Program

1. Usage: `monty file`
	* where file is the path to the file containing Monty byte code
2. If the user does not give any file or more than one argument to your program, print `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
3. If, for any reason, it’s not possible to use read the file, print Error: Can't open file <file>, followed by a new line, and exit with the status `EXIT_FAILURE`
4. If the file contains an invalid instruction, print `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
	* Line numbers always start at 1
5. The monty program runs the bytecodes line by line and stop if:
	* it executed properly every line of the file
	* or it finds an error in the file
	* or an error occured
6. If you can’t malloc anymore, print `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`. You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc`
7. All error messages must be printed on stdout
