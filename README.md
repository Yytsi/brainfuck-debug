# brainfuck-debug
A standard (slow) brainfuck interpreter with useful debugging features.

## Synopsis
Here's a quick rundown of the commands.

```
+    Increment the current cell by 1.
-    Decrement the current cell by 1.
<    Move the pointer to the left.
>    Move the pointer to the right.
.    Print the integer value of the current cell.
,    Read an integer to the current cell.
[    If the value of the current cell is not 0, continue.
      Otherwise, jump over the matching ']' square bracket.
]    Jump to the matching '[' square bracket.

N    Print a newline.
I    Read a character and set the current cell to its ASCII value.
C    Print the character matching the ASCII value of the current cell.
DX   Pretty-prints the first X cells with a Python style, ending with a newline.
      Ex. D3 => [0, 1, 2] where the index values denote the positions of the actual values.
```
     
## Specialities
The input should be placed on the first line, with whitespace as the separator.
`123 A 49` would be an example of such line. Everything after that line is part of the BF-source.

The interpreter ignores all spaces and all tabs, and reads the source of the BF-program from multiple lines.
Lines that begin with a hashtag (#) are ignored by the interpreter.
