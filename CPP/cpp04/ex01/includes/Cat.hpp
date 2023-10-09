#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
		
	public:
		Cat(void);
		Cat(const Cat& copy);
		virtual ~Cat(void);

		Cat& operator=(const Cat& otherCopy);

		void makeSound() const;

		Brain *getBrain(void) const;
};

#endif