# Project: _printf (December 11, 2023)

`printf` is the C language function to do formatted printing,
`_printf` is a mimick of the C standard library function, `printf`

## Description

`_printf` writes output to `stdout`, according to the format specifier function called 
`format`, which then specifies how the arguments are going to be converted.

### The current function DOESN'T accept:
* flag characters (left justify, leading zero print, print plus on positive numbers, invisible plus sign)
* field width
* float precision
* length modifiers

### Only accepts the following
* '%c' (single character)
* '%s' (string of characters)
* '%%' (percent sign (/% also works))
* '%d' (prints a decimal (base 10) number)
* '%i' (prints an integer in base 10)

### Prototype `int _printf(const char *format, ...);`

### Return Value
If return is successful, `_printf` returns the number of characters printed, without the null character (`\0`) characteristic of the string.
If an error is encountered, the function returns `-1`.

### Made for Holberton School
* Alfredo Lehman <[Alfredolsl](https://github.com/Alfredolsl)>
