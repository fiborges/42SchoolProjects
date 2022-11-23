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
#### My grade
<img src="" width="200" height="80"/>

## 💡 About the project
[![42](https://img.shields.io/badge/BornToCode-2_Circle-00babc?style=flat-square&logo=42)](https://42seoul.kr/)

> _This project is pretty straight forward. You will recode printf. Hopefully you will be able to reuse it in future project without the fear of being flagged as a cheater. You will mainly learn how to use variadic arguments._

### What is ft_printf?
ft_printf is an individual project at [42] that requires us to create a function similar to the printf from <stdio.h>. The function ft_printf() (the name comes from “print formatted”) prints a string on the screen using a “format string” that includes the instructions to mix several strings and produce the final string to be printed on the screen.

#### Objectives
- Unix logic

#### Skills
- Rigor
- Unix
- Algorithms & AI

#### My grade
<img src=""/>


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
