# ft_printf
In this project, the printf function must be reprogrammed. The following conversions must be implemented:
```c
* c char
* s char *
* p void *
* d/i int
* u unsigned int
* x/X unsigned int (hexadecimal)
```

## Challenge of the project
The challenge of the project was to implement the conversion. 
Especially the implementation of hexadecimal numbers was very valuable, because it makes you look at converting to other number systems. 
Also the conversion to pointers was interesting, because you had to understand how a pointer is constructed.

## Execution
```bash
git clone https://github.com/HoergerL/ft_printf.git
cd ft_printf
make
```
Then compile your main with the libftprintf.a and add
```c
#include ft_printf.h
```
