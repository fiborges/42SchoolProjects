<h1 align="center">
	🧰 libft
</h1>

<p align="center">
	<b><i>YOUR VERY FIRST OWN LIBRARY</i></b><br>
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project

> _The aim of this project is to code a C library regrouping usual functions that you'll be allowed to use in all your other projects._
	Programming in C can be very tedious when you don't have access to the very useful standard functions.
	This project gives you the opportunity to rewrite those functions to understand them and learn to use them.
	The library will help you for your future projects in C. Through this project, you have the opportunity
	to extend your list of functions in your own way!

#### My grade
<img src="https://github.com/fiborges/42SchoolProjects/blob/main/Ft_libft/Screenshot%202022-11-20%20at%2014.55.31.png" width="200" height="120"/>

## List of functions:

### Functions from `<ctype.h>` library

* [`ft_isascii`](ft_isascii.c)			- test for ASCII character.
* [`ft_isalnum`](ft_isalnum.c)			- alphanumeric character test.
* [`ft_isalpha`](ft_isalpha.c)			- alphabetic character test.
* [`ft_isdigit`](ft_isdigit.c)			- decimal-digit character test.
* [`ft_isprint`](ft_isprint.c)			- printing character test (space character inclusive).
* [`ft_tolower`](ft_tolower.c)			- upper case to lower case letter conversion.
* [`ft_toupper`](ft_toupper.c)			- lower case to upper case letter conversion.

### Functions from `<stdlib.h>` library

* [`ft_atoi`](ft_atoi.c)		- convert ASCII string to integer.
* [`ft_calloc`](ft_calloc.c)	- memory allocation.

### Functions from `<strings.h>` library

* [`ft_bzero`](ft_bzero.c)		- write zeroes to a byte string.
* [`ft_memset`](ft_memset.c)		- write a byte to a byte string.
* [`ft_memchr`](ft_memchr.c)		- locate byte in byte string.
* [`ft_memcmp`](ft_memcmp.c)		- compare byte string.
* [`ft_memmove`](ft_memmove.c)	- copy byte string.
* [`ft_memcpy`](ft_memcpy.c)		- copy memory area.

### Functions from `<string.h>` library

* [`ft_strlen`](ft_strlen.c)				- find length of string.
* [`ft_strchr`](ft_strchr.c)				- locate character in string (first occurrence).
* [`ft_strrchr`](ft_strrchr.c)			- locate character in string (last occurence).
* [`ft_strnstr`](ft_strnstr.c)			- locate a substring in a string (size-bounded).
* [`ft_strncmp`](ft_strncmp.c) 			- compare strings (size-bounded).
* [`ft_strdup`](ft_strdup.c)				- save a copy of a string (with malloc).
* [`ft_strlcpy`](ft_strlcpy.c)			- size-bounded string copying.
* [`ft_strlcat`](ft_strlcat.c)			- size-bounded string concatenation.

### Non-standard functions

* [`ft_itoa`](ft_itoa.c)					- convert integer to ASCII string.
* [`ft_substr`](ft_substr.c)				- extract substring from string.
* [`ft_strtrim`](ft_strtrim.c)			- trim beginning and end of string with the specified characters.
* [`ft_strjoin`](ft_strjoin.c)			- concatenate two strings into a new string (with malloc).
* [`ft_split`](ft_split.c)				- split string, with specified character as delimiter, into an array of strings.
* [`ft_strmapi`](ft_strmapi.c)			- create new string from modifying string with specified function.
* [`ft_striteri`](ft_striteri.c)			- modify string with specified function.
* [`ft_putchar_fd`](ft_putchar_fd.c)		- output a character to given file.
* [`ft_putstr_fd`](ft_putstr_fd.c)		- output string to given file.
* [`ft_putendl_fd`](ft_putendl_fd.c)		- output string to given file with newline.
* [`ft_putnbr_fd`](ft_putnbr_fd.c)		- output integer to given file.

### Linked list functions (bonus)

* [`ft_lstnew`](ft_lstnew_bonus.c)				- create new list.
* [`ft_lstsize`](ft_lstsize_bonus.c)			- count elements of a list.
* [`ft_lstlast`](ft_lstlast_bonus.c)			- find last element of list.
* [`ft_lstadd_back`](ft_lstadd_back_bonus.c)	- add new element at end of list.
* [`ft_lstadd_front`](ft_lstadd_front_bonus.c)	- add new element at beginning of list.
* [`ft_lstdelone`](ft_lstdelone_bonus.c)		- delete element from list.
* [`ft_lstclear`](ft_lstclear_bonus.c)			- delete sequence of elements of list from a starting point.
* [`ft_lstiter`](ft_lstiter_bonus.c)			- apply function to content of all list's elements.
* [`ft_lstmap`](ft_lstmap_bonus.c)				- apply function to content of all list's elements into new list.


## 📋 Testing

You can use any of this testers to test the project. Be careful to do your tests, these programs are not 100% foolproof!


* [Tripouille/libfTester](https://github.com/Tripouille/libftTester)
* [ska42/libft-war-machine](https://github.com/ska42/libft-war-machine)
* [alelievr/libft-unit-test](https://github.com/alelievr/libft-unit-test)
