#include "Span.hpp"

#define LOG(title) std::cout << GREEN "\n\t===== Testing " << title << " =====\n\n" RESET;

void testShortestSpanFunctionality(void)
{
	Span span(3);

	LOG("Shortest Span");
	std::cout << "Filling span until N=3...\n"; 
	span.fillWithRandomNumbers();
	std::cout << span;
	std::cout << "Shortest span: " << span.calculateShortestSpan() << "\n";
}

void testLongestSpanFunctionality(void)
{
	Span span(10);

	LOG("Longest Span");
	std::cout << "Filling span until N=10...\n"; 
	span.fillWithRandomNumbers();
	std::cout << span;
	std::cout << "Longest span: " << span.calculateLongestSpan() << "\n";
}

void testAddNumberFunctionality(void)
{
	LOG("Add Number");

	try
	{
		Span fullSpan(10);

		std::cout << "Filling span until N=10...\n"; 
		fullSpan.fillWithRandomNumbers();
		std::cout << fullSpan;

		std::cout << "Trying to add an 11th number...\n"; 
		fullSpan.addNumber(333333);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
}

void testNoSpanFunctionality(void)
{
	LOG("Empty Span");
	try
	{
		Span emptySpan;
		emptySpan.calculateShortestSpan();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
}

void testLargeSetFunctionality(void)
{
	LOG("Large Span Set");
	try
	{
		Span largeSpan(15000);

		largeSpan.fillWithRandomNumbers();
		std::cout << largeSpan;
		std::cout << "Shortest span: " << largeSpan.calculateShortestSpan() << "\n";
		std::cout << "Longest span: " << largeSpan.calculateLongestSpan() << "\n";
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
}


int main(int argc, char **argv)
{
	int					selectedTest;

	void (*testers[])() = 
	{
		&testShortestSpanFunctionality,
		&testLongestSpanFunctionality,
		&testAddNumberFunctionality,
		&testLargeSetFunctionality,
		&testNoSpanFunctionality,
	};

	std::srand(std::time(NULL));
	if (argc < 2) 
    {
        std::cerr << RED <<  "Usage: " << argv[0] << " <test_number>\n" << RESET;
        return 1;
    }

    std::istringstream argumentStream(argv[1]);
    argumentStream >> selectedTest;

    if (!argumentStream || selectedTest < 0 || selectedTest > 4) 
    {
        std::cerr << RED << "Error: Invalid test number. Please provide a valid test number between 0 and 4.\n" << RESET;
        return 1;
    }

    testers[selectedTest]();
    return 0;
}