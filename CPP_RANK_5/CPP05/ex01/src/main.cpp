#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

# define PRINT_ERROR(x) 		std::cout << x << std::endl
# define ERROR_MESSAGE(e)	PRINT_ERROR("Usage: " << e << " test_number")
# define ERROR_NOT_INTEGER	PRINT_ERROR("Error: test number must be a number")
# define ERROR_OUT_OF_RANGE	PRINT_ERROR("Error: test number must be bounded between 0 and 1")

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

void test_form_signing(void)
{
	std::cout << GREEN << "\n\t\t\tTesting Form Part!!!\n" << RESET << std::endl;

	Bureaucrat filipa("Filipa ", 1);
	Form filipaForm("Filipa_Form1: ", 1, 1);
	try
	{
		filipa.signForm(filipaForm);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << filipaForm;
	
	Bureaucrat maria_150("Maria_Max", 150);
	Form Form42("Form42", 42, 42);
	try
	{
		maria_150.signForm(Form42);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	
	std::cout << Form42;
}

void test_form_constructor(void)
{
	std::cout << GREEN << "\n\t\tTesting Form Constructor\n" << RESET << std::endl;

	try
	{
		Form Form1("Form1: ", 1, 1);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	
	try
	{
		Form Form0("Form0: ", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	
	try
	{
		Form Form150("Form150: ", 150, 150);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try
	{
		Form Form151("Form151: ", 151, 151);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int main(int argc, char **argv)
{
	int					test_number;
	std::stringstream	stream;

	if (argc < 2)
		return (ERROR_MESSAGE(argv[0]), 1);
	stream << argv[1];
	if (!(stream >> test_number))
		return (ERROR_NOT_INTEGER, 1);
	if (test_number == 0)
		test_form_constructor();
	else if (test_number == 1)
		test_form_signing();
	else
		return (ERROR_OUT_OF_RANGE, 1);
	return (0);
}






