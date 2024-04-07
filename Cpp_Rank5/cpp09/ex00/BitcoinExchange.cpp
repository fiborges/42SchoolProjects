/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: firibeir <firibeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:17:41 by firibeir          #+#    #+#             */
/*   Updated: 2024/04/07 12:17:41 by firibeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	this->getData();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void)
{
	
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src)
{
	*this = src;
	return *this;
}

void BitcoinExchange::getData()
{
	std::ifstream data("data.csv");

	if (!data.is_open())
	{
		std::cout << RED << "Error opening file" << RESET << std::endl;
		return;
	}

	std::string line;
	std::string date;
	std::string rate;

	std::getline(data, line); // skip first line
	while (std::getline(data, line))
	{
		date = line.substr(0, line.find(','));
		rate = line.substr(line.find(',') + 1, line.length());
		map_conteiner[date] = std::atof(rate.c_str());
	}
	data.close();
}

void	BitcoinExchange::calculateExchange(const char *inFile)
{
	std::ifstream file(inFile);
	if (!file.is_open())
	{
		std::cout << RED << "Error opening file" << RESET << std::endl;
		return ;
	}
	std::string line;
	std::string date;
	float amount;
	
	std::getline(file, line); // skip first line
	while (std::getline(file, line))
	{
		if (line.empty() || line.length() < 12)
		{
			std::cout << RED << "Error:" << RESET << "Bad input => " << line << std::endl;
			continue;
		}
		size_t divide = line.find_first_of(" |");
		date = line.substr(0, divide);
		amount = std::atof(line.substr(line.find('|') + 2).c_str());
		if (!checkDate(date)){

			std::cout << RED << "Error:" << RESET << "Bad date => " << date << std::endl;
		}
		else if (amount < 0)
			std::cout << RED << "Error:" << RESET << "not a positive number." << std::endl;
		else if (amount > 1000)
			std::cout << RED << "Error:" << RESET << "too large a number." << std::endl;
		else
		{
			std::map<std::string, float>::const_iterator iterar = this->map_conteiner.upper_bound(date);
			if (iterar->first.compare(date) != 0)
				--iterar;
			std::cout << date << " => " << amount << " = " << iterar->second*amount << "\n";
		}
	}
	file.close();
}

bool	BitcoinExchange::checkDate(const std::string date)
{
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);


	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		return false;
	if (std::atoi(year.c_str()) < 0 || std::atoi(year.c_str()) > 2024)
		return false;
	if (std::atoi(month.c_str()) < 0 || std::atoi(month.c_str()) > 12)
		return false;
	if (std::atoi(day.c_str()) < 0 || std::atoi(day.c_str()) > 31)
		return false;
	if (std::atoi(year.c_str()) < 2009 || (atoi(year.c_str()) == 2009 && atoi(month.c_str()) == 1 && atoi(day.c_str()) < 2))
		return false;
	return true;
}

