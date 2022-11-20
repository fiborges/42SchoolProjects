<h1 align="center">
	🧰 ft_printf
</h1>

<p align="center">
	<b><i>Because putnbr and putstr aren’t enough</i></b><br>
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project

> _This project is pretty straight forward. You will recode printf. Hopefully you will be able to reuse it in future project without the fear of being flagged as a cheater. You will mainly learn how to use variadic arguments._

### What is ft_printf?
ft_printf is an individual project at [42](https://www.42istanbul.com.tr/) that requires us to create a function similar to the printf from <stdio.h>. The function ft_printf() (the name comes from “print formatted”) prints a string on the screen using a “format string” that includes the instructions to mix several strings and produce the final string to be printed on the screen.

### Application flow
Click [here](https://excalidraw.com/#json=X5IF2CEVuO8EhAyX9bwMZ,42SQg0D6nJcF7hwcDG1dVw) for the interactive link.

#### Objectives
- Unix logic

#### Skills
- Rigor
- Unix
- Algorithms & AI

#### My grade
<img src="./images/grade.png" width="150" height="150"/>

## List of functions:

* [`ft_convert`](/sources/ft_convert.c)			- converts num to related numerical base.
* [`ft_putnbr`](/sources/ft_putnbr.c)			  - prints the number on the screen.
* [`ft_putstr`](/sources/ft_putstr.c)			  - prints given string on the screen.
* [`ft_putchar`](/sources/ft_putstr.c)			- prints given character on the screen.
* [`ft_putunbr`](/sources/ft_putunbr.c)			- prints given number on the screen (only positive).
* [`ft_putptr`](/sources/ft_putptr.c)			- prints given data by hexidecimal numerical base on the screen
* [`ft_strlen`](/sources/ft_strlen.c)			  - computes length of given string.
* [`ft_printf`](/sources/ft_printf.c)			  - prints a string on the screen using a “format string” that includes the instructions to mix several strings and produce the final string to be printed on the screen.


**Example of a main**
```C
#include "ft_printf.h"

int main(void)
{
  ft_printf("%s", "Hello World");
  ft_printf("%c", '\n');
  ft_printf("%d", 123456789);
  ft_printf("%c", '\n');
  ft_printf("%X", 987654321);
 return (0);
}

/**
* output: 
* Hello World
* 123456789
* 3ADE68B1
**/
```

## 📋 Testing

You can use any of this third party testers to test the project

* [Tripouille/printfTester](https://github.com/Tripouille/printfTester)
* [paulo-santana/ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester)
