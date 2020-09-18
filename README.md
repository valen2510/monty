<p align="center">
<img src="https://tctechcrunch2011.files.wordpress.com/2015/11/holberton-logo-horizontal.jpg" width="450" height="250">	
<h1> Monty</h1></p>

<h3> 📝 Description</h3>
<p>Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.</p>

<h3> 📚 Monty byte code file</h3>
<p>Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
monty]\--> cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
monty]\-->

```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
monty]\--> cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
monty]\-->

```
</p>

<h3> ⭐️ Compilation</h3>

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty

```

<h3> 🚀 Usage</h3>

```
$ ./monty bytecode_file

```

<h3> ✨ Project Opcode functions</h3>

 Opcode        | Description |
| ----------- | ----------- |
|push   | Pushes an element to the stack.|
|pall   | Prints all the values on the stack, starting from the to of the stack.|
|pint   | Prints the value at the top of the stack.|
|pop    | Removes the to element of the stack. |
|swap   | Swaps the top to elements of the stack.|
|nop    | This opcode does not do anything.|
|sub    | Subtracts the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|div    | Divides the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|mul | Multiplies the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|mod    | Computes the remainder of the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.|
|pchar  | Prints the integer stored in the top of the stack as its ascii value representation.|
|pstr   | Prints the integers stored in the stack as their ascii value representation. It stops printing when the value is 0, when the stack is over and when the value of the element is a non-ascii value.|
|rotl   | Rotates the top of the stack to the bottom of the stack.|
|rotr   | Rotates the bottom of the stack to the top of the stack.|

<h3> 🤝 Contributors</h3>

<a href="https://github.com/valen2510" target="_blank">
        <img src="https://avatars3.githubusercontent.com/u/65981858?s=460&u=917bf8544c11bfc83b5a9fd961fc72ef25e3188a&v=4" style="float: center; margin-right: 10px" height="50" width="50">
</a>

---

<p align="center">
        <a href="https://twitter.com/DaftVal" target="_blank">
            <img alt="twitter_page" src="https://github.com/gedafu/readme-template/blob/master/images/twitter.png" style="float: center; margin-right: 10px" height="50" width="50">
        </a>
        <a href="https://www.linkedin.com/in/valentina-ramirez-8b2806138/" target="_blank">
            <img alt="linkedin_page" src="https://github.com/gedafu/readme-template/blob/master/images/linkedin.png" style="float: center; margin-right: 10px" height="50"  width="50">
        </a>
        <a href="https://medium.com/@1826" target="_blank">
            <img alt="medium_page" src="https://github.com/gedafu/readme-template/blob/master/images/medium.png" style="float: center; margin-right: 10px" height="50" width="50">
        </a>
<br>
<p align="center">
<b>Holberton School - Colombia<b><br>
</p>
<p align="center">
<b>September, 2020.<b>
</p>