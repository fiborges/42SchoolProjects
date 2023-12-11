#include "../includes/Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void testForm(AForm& form, Bureaucrat &bureaucrat)
{
	try
	{
		bureaucrat.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << "\n";
	}
}

void testPresidentialPardonForm(void)//0
{
	std::cout << GREEN << "\n\tTesting Presidential Pardon Form\n\n" << RESET;
	PresidentialPardonForm form(CYAN "George W. Bush" RESET);
	Bureaucrat b(MAGENTA "Abraham Lincon" RESET, 1);
	b.signForm(form);
	testForm(form, b);
}

void testRobotomyRequestForm(void)// 1
{
	std::cout << GREEN << "\n\tTesting Robotomy Request Form\n\n" << RESET;
	RobotomyRequestForm form(CYAN "HUMAN" RESET);
	Bureaucrat b(CYAN "Chat-GPT: " RESET, 40);
	b.signForm(form);
	testForm(form, b);
}

void testShrubberyCreationForm(void)//2
{
	std::cout << GREEN << "\n\tTesting Shrubbery Creation Form\n\n" << RESET;
	ShrubberyCreationForm form("drawing");
	Bureaucrat b(CYAN "Leonardo da Vinci" RESET, 130);
	b.signForm(form);
	testForm(form, b);
}

void testExecutingUnsignedForm(void)//3
{
	std::cout << GREEN << "\n\tTesting executing unsigned form\n\n" << RESET;
	RobotomyRequestForm form("HUMAN BRAIN");
	Bureaucrat b("ROBOT: ", 40);
	testForm(form, b);
}

void testExecutingWithLowGrade(void)//4
{
	std::cout << GREEN << "\n\tTesting bureaucrat without grade to execute\n\n" << RESET;
	PresidentialPardonForm form(MAGENTA "Prisoner of Azkaban" RESET);
	Bureaucrat b(CYAN "DUMBLEDORE: " RESET, 5);
	Bureaucrat b2(CYAN "SIRIUS: " RESET, 150);
	b.signForm(form);
	testForm(form, b2);
}

int main(int argc, char **argv)
{
	int					test_number;
	std::stringstream	output;
	void (*functions_test[])() = 
	{
		testPresidentialPardonForm,
		testRobotomyRequestForm,
		testShrubberyCreationForm,
		testExecutingUnsignedForm,
		testExecutingWithLowGrade
	};

	std::srand(time(NULL));
	if (argc < 2)
		return (ERROR_MESSAGE(argv[0]), 1);
	output << argv[1];
	if (!(output >> test_number))
		return (ERROR_NOT_INTEGER, 1);
	if (test_number < 0 || test_number > 4)
		return (ERROR_OUT_OF_RANGE, 1);
	functions_test[test_number]();
	return (0);
}






