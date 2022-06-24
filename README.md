# Monty Byte Code Interpreter! - Stacks, Queues - LIFO, FIFO 🐍❤️‍
  
#### Monty 0.98 is a scripting language that is first compiled into Monty byte codes(just like Python). It relies on a unique stack, with specific instructions to manipulate it.  
  
  
## PURPOSE 🧮  
Monty is a simple byte code interpreter that incorportates `stack` [**LIFO** (last in first out)] and `queue` [**FIFO** (first in first out)] by interpreting opcodes to perform specified tasks in order to manipulate the stack.

  
## USAGE 💻🖱️
Please use GCC 4.8.4 compiler or later.  
  
```  
**$** git clone https://github.com/brerickner/monty.git 
**$** gcc -Wall -Werror -Wextra -pedantic *.c -o monty  
**$** ./monty <file_name.m>  
```  
 
## MONTY IN ACTION! 🐍💥  
  
Examples how to use Monty with test files(meow1.m, meow2.m):  
  
```  
**$** cat -e meow1.m  
push 1$  
push 2$  
push 3$  
pall$

**$** ./monty meow1.m  
3  
2  
1  
  
**$** cat meow2.m  
push 1  
push 2  
push 3  
pall  
swap  
pall

**$** ./monty meow2.m  
3  
2  
1  
2  
3  
1   
``` 

## OPCODES 🖥️🔡

Listed below are the opcodes that can be used with Monty:  
  
**opcode** | Function
--------|---------------  
**push** | Pushes an element to the stack  
**pall**| Prints all the values on the stack, starting from the top of the stack  
**pint** | Prints the value at the top of the stack, followed by a new line  
**pop** | Removes the top element of the stack  
**swap** | Swaps the top two elements of the stack  
**add** | Adds the top two elements of the stack  
**nop** | Doesn’t do anything 
  
  

## File Descriptions  📂🗃️
  
Description of files contained within this repo:  
  
**File** | Description  
--------|---------------  
**free_stack.c** | Contains function to free memory allocated for stack.    
**monty.h **| Header file that contains function prototypes and data structures.  
**monty9.c** | Contains main function and function to get instructions of opcodes.
**opCodeFunc2.c** | Contains functions for add, sub and mul. 
**opcodefunc10.c** | Contains functions for push, pall, pint, pop and nop.
**opcodefunc2.c **| Contains functions that swaps top two elements on stack.   

## Authors 👩‍💻 👩‍💻
  
**Bre Rickner** 🤜 🤛 **Valerie Nierenberg**
 
