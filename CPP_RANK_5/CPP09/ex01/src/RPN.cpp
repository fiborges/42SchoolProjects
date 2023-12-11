# include "RPN.hpp"

bool isOperator(char c)
{
	return ((c == '-') || (c == '+') || (c == '*') || (c == '/'));
}

bool isCharacterValid(char c)
{
	return ((c >= '0' && c <= '9') || isOperator(c));
}

void performOperationAndPushResult(std::stack<int> &stack, char symbol)
{
	int	first; 
	int	second;

	second = stack.top();
	stack.pop();
	first = stack.top();
	stack.pop();
	
	if (symbol == '+')
		stack.push(first + second);
	else if (symbol == '-')
		stack.push(first - second);
	else if (symbol == '*')
		stack.push(first * second);
	else
		stack.push(first / second);
	std::cout << first << symbol << second << "=" << stack.top() << std::endl;
}

bool processRPNExpression(std::string expression)
{
    char symbol;
    std::stack<int> stack;
    std::stringstream stream(expression);

    while (stream >> symbol)
    {
        if (!isCharacterValid(symbol))
        {
            std::cout << RED <<"Error: Invalid symbol '" << symbol << "'" << std::endl << RESET;
            return false;
        }
        if (isOperator(symbol) && stack.size() < 2)
        {
            std::cout << RED << "Error: Not enough arguments for operator '" << symbol << "'" << std::endl << RESET;
            return false;
        }
        if (!isOperator(symbol))
        {
            stack.push(symbol - '0');
            continue;
        }
        else
        {
            performOperationAndPushResult(stack, symbol);
        }
    }
    if (stack.size() != 1)
    {
        std::cout << RED << "Error: Leftover elements in the stack" << std::endl << RESET;
        return false;
    }
    std::cout << stack.top() << std::endl;
    return true;
}