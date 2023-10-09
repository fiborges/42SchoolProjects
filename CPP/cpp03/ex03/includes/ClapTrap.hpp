#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cstdlib>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN     "\033[36m"
#define MAGENTA  "\033[35m"

# define DEBUG

# ifdef DEBUG
#	define LOG(str) std::cout << str << std::endl;
# else
#	define LOG(str)
# endif

class ClapTrap
{
	protected:

		std::string name;
		int	hitPoints;//health
		int energyPoints;//energy
		int attackDamage;//damage
		
	public:

		ClapTrap(void);
		ClapTrap(const ClapTrap& copy);
		ClapTrap(const std::string& name);

		virtual ~ClapTrap(void);

		ClapTrap& operator=(const ClapTrap& otherCopy);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		int getCurrentHealth(void) const;
		int getCurrentEnergy(void) const;
		int getCurrentAttackPower(void) const;
};

std::ostream& operator<<(std::ostream& output, const ClapTrap& fixedNumber);

#endif