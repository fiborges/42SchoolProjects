#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog& copy);
		virtual ~Dog(void);

		Dog& operator=(const Dog& otherCopy);

		void makeSound() const;
};

#endif