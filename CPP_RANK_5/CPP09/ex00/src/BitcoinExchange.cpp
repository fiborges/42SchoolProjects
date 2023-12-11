#include "./BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source) : _Data(source._Data)
{
	*this = source;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return (*this);
	this->_Data = other._Data;
	return (*this);
}

std::map<std::string, double> BitcoinExchange::getConversionData() const
{
    return _Data;
}


void BitcoinExchange::loadConversionData()
{
	std::string currentLine;
	bool isfirstLine = false;

	std::ifstream dataFile("data.csv");

	while (getline(dataFile, currentLine))
	{
		if (isfirstLine) //se for a 1 linha
		{
			_Data.insert(std::pair<std::string, double>(currentLine.substr(0, currentLine.find(',')), std::stod(currentLine.substr(currentLine.find(',') + 1, currentLine.length()))));
		}
		else
			isfirstLine = true;
	}
	dataFile.close();
}

void BitcoinExchange::processInputFile(std::string fileName)
{
	std::string line;
	bool firstLine = false;
	std::ifstream dataFile(fileName);

	if (!dataFile.is_open()) 
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}

	while (getline(dataFile, line))
	{
		if (firstLine)
		{
			std::string date;
			std::string year;
			std::string month;
			std::string day;
			std::string value;

			size_t del = line.find('|');

			if (del == std::string::npos) 
			{
				std::cout << "Error: bad input => " + line << std::endl;
				continue;
			}

			date = line.substr(0, del);
			value = line.substr(del + 2, line.length());

			year = date.substr(0, date.find('-'));
			date.erase(date.begin(), date.begin() + date.find('-') + 1);
			month = date.substr(0, date.find('-'));
			date.erase(date.begin(), date.begin() + date.find('-') + 1);
			day = date.substr(0, date.length());
			date = line.substr(0, del);
			date.pop_back();
			if (this->validateDate(std::stoi(year), std::stoi(month), std::stoi(day))) {
				double totalValue = this->bitcoinConverter(date, std::stod(value));
				if (totalValue == -1) 
				{
					std::cout << "Error: not a positive number" << std::endl;
				} else if (totalValue == -2) 
				{
					std::cout << "Error: too large number" << std::endl;
				} else 
				{
					std::cout << date + " => " + value + " = " << totalValue << std::endl;
				}
			} 
			else 
			{
				std::cout << "Error: bad input => " + date << std::endl;
			}
		} 
		else 
		{
			firstLine = true;
		}
	}
}

bool BitcoinExchange::validateDate(int year, int month, int day) 
{
	if (year < 1800 || year > 3000) return false;
	if (day < 1 || day > 31) return false;
	if (month == 2)
	{
		if (isLeapYear(year))//se for bissexto
			return (day <= 29);
		else
			return (day <= 28);
	}
	if (month == 4 || month == 6 ||
			month == 9 || month == 11)
		return (day <= 30);
	return true;
}


bool BitcoinExchange::isLeapYear(int year)//verifica se o ano é bissexto
{
	return (((year % 4 == 0) &&
			(year % 100 != 0)) ||
			(year % 400 == 0));
}


double BitcoinExchange::bitcoinConverter(std::string date, double value) 
{
	if (value < 0) 
	{
		return -1;
	} else if (value > 1000) 
	{
		return -2;
	} else 
	{
		std::map<std::string, double>::iterator it = _Data.lower_bound(date);
		if (it != _Data.begin() && it->first != date)
			it--;
		return value * it->second;
	}
}