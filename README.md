<p align="center">
<img src="https://tctechcrunch2011.files.wordpress.com/2015/11/holberton-logo-horizontal.jpg" width="450" height="250">	
<h1> Printf project</h1></p>

<h3> Description</h3>
<p>pMonty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.</p>

<h3> Compilation</h3>

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty

```


<h3> Usage</h3>

```
$ ./monty bytecode_file
```


<h3>Project Opcode functions</h3>

 Opcode        | Description |
| ----------- | ----------- |
|push   | Pushes an element to the stack.|
|pall   | Prints all the values on the stack, starting from the to of the stack.|
|pint   | Prints the value at the top of the stack.|
|pop    | Removes the to element of the stack. |
|swap   | Swaps the top to elements of the stack.|
|nop    | This opcode does not do anything.|

<h3>Contributors</h3>

Valentina Jaramillo - [@valen2510](https://github.com/valen2510)<br>