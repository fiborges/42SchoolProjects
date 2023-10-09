#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <cstdlib>

//# define DEBUG

# ifdef DEBUG
#	define LOG(str) std::cout << str << std::endl;
# else
#	define LOG(str)
# endif

// Cores ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN     "\033[36m"
#define MAGENTA  "\033[35m"
#define BLUE     "\033[34m"

class Harl
{
	public:
		
		Harl(void);
		~Harl(void);

		
		void complain (std::string level);
		
	private:
	
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif