#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>
# include <cstdlib>

# define NUM_IDEAS 100

class Brain
{
	private:
		std::string ideas[NUM_IDEAS];
	
	public:
		Brain(void);
		Brain(const Brain& copy);
		~Brain(void);

		void use(void) const;

		Brain& operator=(const Brain& otherCopy);
};

#endif