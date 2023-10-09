#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# define DEBUG

# include <iostream>
# include "Animal.hpp"
# ifdef DEBUG
# 	define LOG(str) std::cout << str << std::endl;
# else
#	define LOG(str)
# endif

class WrongAnimal
{
	protected:
		std::string type;
		
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& copy);
		virtual ~WrongAnimal(void);

		WrongAnimal& operator=(const WrongAnimal& otherCopy);

		void makeSound() const;

		std::string getType(void) const;
		void setType(const std::string& type);
};

#endif