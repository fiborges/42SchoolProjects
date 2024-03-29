#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <cstdlib>

// Cores ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN     "\033[36m"
#define MAGENTA  "\033[35m"

class Zombie
{
	public:
		Zombie( void );
		Zombie(std::string name);
		~Zombie();
		void announce( void );
		void setName(std::string name);

	private:
		std::string name;
};

Zombie* newZombie( std::string name );

void randomChump( std::string name );

Zombie	*zombieHorde(int N, std::string name);

#endif