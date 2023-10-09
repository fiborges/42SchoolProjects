#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"
# include "Animal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat& copy);
		virtual ~WrongCat(void);

		WrongCat& operator=(const WrongCat& otherCopy);

		void makeSound() const;
};

#endif