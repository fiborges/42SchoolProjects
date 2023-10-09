#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# define DEBUG

# include <iostream>
# ifdef DEBUG
# 	define LOG(str) std::cout << str << std::endl;
# else
#	define LOG(str)
# endif

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN     "\033[36m"
#define MAGENTA  "\033[35m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[95m"

class Animal
{
	protected:
		std::string type;
		
	public:
		Animal(void);
		Animal(const Animal& copy);
		virtual ~Animal(void);

		Animal& operator=(const Animal& otherCopy);

		virtual void makeSound() const;

		std::string getType(void) const;
		void setType(const std::string& type);
};

#endif