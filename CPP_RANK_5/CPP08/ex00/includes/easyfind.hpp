#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <limits>
# include <algorithm>
# include <vector>
# include <list>
# include <deque>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

template <typename T>
int easyfind(T container, int tofind);

# include "easyfind.tpp"

#endif