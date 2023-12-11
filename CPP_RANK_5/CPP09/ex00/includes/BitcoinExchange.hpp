#pragma once


#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _Data;
	public:
		BitcoinExchange();
		// BitcoinExchange( std::string filePath );
		BitcoinExchange( const BitcoinExchange & src );
		~BitcoinExchange();

		BitcoinExchange & operator = ( const BitcoinExchange & rhs );
		std::map<std::string, double> getConversionData() const;

		void loadConversionData();
		void processInputFile(std::string fileName);
		bool validateDate(int year, int month, int day);
		bool isLeapYear(int year);
		double bitcoinConverter(std::string date, double value);

};