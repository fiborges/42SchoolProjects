#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

bool isOperator(char c);

bool isCharacterValid(char c);

void performOperationAndPushResult(std::stack<int> &stack, char symbol);

bool processRPNExpression(std::string expression);

#endif