#ifndef Dog_HPP
# define Dog_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	
	public:
		Dog(void);
		Dog(const Dog& copy);
		virtual ~Dog(void);

		Dog& operator=(const Dog& otherCopy);

		void makeSound() const;

		Brain *getBrain(void) const;
};

#endif