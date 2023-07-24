0x11. C – printf group project with formatted output conversion #include “main.h” and prototype int _printf(const char *format, ...); 
Description:
 The _printf() function produces output according to a format as described . it also writes output to stdout. It writes output under the control of a format string that specifies how subsequent arguments() are converted for output.
The format string is a character string, beginning and ending in its initial shift state. The format string is composed of zero or more directives; ordinary characters not “%”, which are copied unchanged to the output stream
 and conversion specifications, each of which results in fetching zero or more subsequent arguments. 
Each conversion specification is introduced by the character % and ends with conversion specifier.Conversion specifiers are characters that specify the type of conversion to be applied. 
The conversion specifiers and their meaning are:
•	d, i: The int argument should be signed decimal notation, and the resulting number is written.
•	c: The int argument is converted to a char, and the resulting character is written.
•	s: The const char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating null byte ('\0').
•	%: A '%' is written. No argument is converted. The complete conversion specification is '%%'.

