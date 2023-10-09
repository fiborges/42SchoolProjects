#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& copy);
		virtual ~Cat(void);

		Cat& operator=(const Cat& otherCopy);

		void makeSound() const;
};

#endif