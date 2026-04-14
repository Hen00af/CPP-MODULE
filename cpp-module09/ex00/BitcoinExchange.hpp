#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, double>	_database;

	BitcoinExchange();

	bool	isValidDate(std::string const &date) const;
	bool	loadDatabase(std::string const &filename);

public:
	BitcoinExchange(std::string const &dbFile);
	BitcoinExchange(BitcoinExchange const &copy);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange const &rhs);

	void	processInput(std::string const &inputFile) const;
};

#endif
