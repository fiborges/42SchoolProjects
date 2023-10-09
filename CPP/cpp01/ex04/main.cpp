#include <iostream>
#include <cstdlib>
#include <fstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN     "\033[36m"
#define MAGENTA  "\033[35m"

void erro_msg(void)
{
	std::cout << RED << "Number of arguments Invalid. [./program][Arquivo][string1][string2]" << RESET << std::endl;
	exit(1);
}

std::string readFileContents(char *filename)
{
	std::string line;
	std::string fileContent;
	std::ifstream fileStream;
	
	fileStream.open(filename, std::ios::in);
	if (fileStream.fail())
	{
		std::cout << RED << "Failed to open '" << RESET << filename << "'" << std::endl;
		exit(2);
	}
	while (1)
	{
		std::getline(fileStream, line);
		fileContent += line;
		if (fileStream.eof())
			break;
	}
	fileStream.close();
	return (fileContent);
}

std::string replaceSubstring(const std::string &input, 
	const std::string &oldString, const std::string &newString)
{
	size_t		startIndex;
	size_t		endIndex;
	std::string new_string;

	endIndex = 0;
	while (1)
	{
		startIndex = input.find(oldString, endIndex);
		new_string += input.substr(endIndex, startIndex - endIndex);
		if (startIndex == std::string::npos)
			break;
		new_string += newString;
		endIndex = startIndex + oldString.length();
	}
	return (new_string);
}

void writeToFile(const std::string& filename, const std::string &result)
{
	std::ofstream fileStream;

	fileStream.open((filename + ".replace").c_str(), std::ios::out);
	if (fileStream.fail())
	{
		std::cout << RED << "Failed to open '" << RESET << filename << "'" << std::endl;
		exit(2);
	}
	fileStream << result;
	fileStream.close();
}

int main(int argc, char **argv)
{
	if (argc < 4)
		erro_msg();
	std::string inputContent;
	std::string oldString;
	std::string newString;
	std::string outputContent;
	
	oldString = argv[2];
	newString = argv[3];

	inputContent = readFileContents(argv[1]);
	if (oldString != "")
		outputContent = replaceSubstring(inputContent, oldString, newString);
	else
		for (std::size_t i = 0; i < inputContent.length(); i++)
			outputContent += newString;
	writeToFile(argv[1], outputContent);
}
