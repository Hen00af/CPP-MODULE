#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string const &dbFile)
{
	if (!loadDatabase(dbFile))
		throw std::runtime_error("Error: could not open database file.");
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
	: _database(copy._database)
{
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
		_database = rhs._database;
	return *this;
}

bool operator<(Date const &a, Date const &b)
{
	if (a.y != b.y)
		return a.y < b.y;
	if (a.m != b.m)
		return a.m < b.m;
	return a.d < b.d;
}

bool BitcoinExchange::parseDate(std::string const &str, Date &date) const
{
	if (str.length() != 10 || str[4] != '-' || str[7] != '-')
		return false;

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (str[i] < '0' || str[i] > '9')
			return false;
	}

	date.y = std::atoi(str.substr(0, 4).c_str());
	date.m = std::atoi(str.substr(5, 2).c_str());
	date.d = std::atoi(str.substr(8, 2).c_str());

	if (date.y < 1 || date.m < 1 || date.m > 12)
		return false;
	if (date.d < 1 || date.d > 31)
		return false;

	if (date.m == 2)
	{
		bool leap;

		leap = (date.y % 4 == 0 && date.y % 100 != 0)
			|| (date.y % 400 == 0);
		if (date.d > (leap ? 29 : 28))
			return false;
	}
	else if (date.m == 4 || date.m == 6 || date.m == 9 || date.m == 11)
	{
		if (date.d > 30)
			return false;
	}

	return true;
}

std::string BitcoinExchange::dateToString(Date const &date) const
{
	std::ostringstream oss;

	oss << date.y << "-";
	if (date.m < 10)
		oss << "0";
	oss << date.m << "-";
	if (date.d < 10)
		oss << "0";
	oss << date.d;

	return oss.str();
}

bool BitcoinExchange::loadDatabase(std::string const &filename)
{
	std::ifstream file(filename.c_str());

	if (!file.is_open())
		return false;

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::string::size_type pos;
		std::string dateStr;
		Date date;
		double rate;

		pos = line.find(',');
		if (pos == std::string::npos)
			continue;

		dateStr = line.substr(0, pos);
		if (!parseDate(dateStr, date))
			continue;

		rate = std::atof(line.substr(pos + 1).c_str());
		_database[date] = rate;
	}

	file.close();
	return true;
}

void BitcoinExchange::processInput(std::string const &inputFile) const
{
	std::ifstream file(inputFile.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::string::size_type sep;
		std::string dateStr;
		std::string valueStr;
		Date date;
		char *endptr;
		double value;

		sep = line.find(" | ");
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		dateStr = line.substr(0, sep);
		valueStr = line.substr(sep + 3);

		if (!parseDate(dateStr, date))
		{
			std::cerr << "Error: bad input => " << dateStr << std::endl;
			continue;
		}

		value = std::strtod(valueStr.c_str(), &endptr);
		if (*endptr != '\0' && *endptr != '\r')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<Date, double>::const_iterator it;
		it = _database.lower_bound(date);

		if (it == _database.end() || it->first < date || date < it->first)
		{
			if (it == _database.begin())
			{
				std::cerr << "Error: bad input => " << dateStr << std::endl;
				continue;
			}
			--it;
		}

		std::cout << dateToString(date)
				  << " => " << value
				  << " = " << value * it->second
				  << std::endl;
	}

	file.close();
}