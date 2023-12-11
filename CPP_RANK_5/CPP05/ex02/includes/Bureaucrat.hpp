#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <cstdlib>
# include <sstream>
# include "AForm.hpp"

# define DEBUG

# ifdef DEBUG
#  define LOG(str) std::cout << str << std::endl;
# else
#  define LOG(str)
# endif

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;
	
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat(const std::string &name, int grade);
		
		std::string getName(void) const;
		int getGrade(void) const;
		
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(AForm& form);
		void executeForm(AForm const& form);
			
		Bureaucrat& operator=(const Bureaucrat& otherCopy);

	class GradeTooHighException : public std::exception
	{
		public:
			//A função what() é uma função virtual da classe std::exception
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};
//sobrecarga do operador de inserção (<<) para imprimir o objeto
std::ostream& operator<<(std::ostream& output, const Bureaucrat& fixedNumber);

#endif

//sobrecarga é um conceito importante em programação que se refere à capacidade 
//de definir várias versões de funções ou operadores com o mesmo nome, mas com 
//diferentes parâmetros