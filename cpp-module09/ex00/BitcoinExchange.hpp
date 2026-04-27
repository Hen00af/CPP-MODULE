#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

struct Date
{
	int y;
	int m;
	int d;
};

bool operator<(Date const &a, Date const &b);

class BitcoinExchange
{
private:
	std::map<Date, double> _database;

	bool		parseDate(std::string const &str, Date &date) const;
	std::string	dateToString(Date const &date) const;

public:
	BitcoinExchange();
	BitcoinExchange(std::string const &dbFile);
	BitcoinExchange(BitcoinExchange const &copy);
	~BitcoinExchange();

	BitcoinExchange &operator=(BitcoinExchange const &rhs);

	bool	loadDatabase(std::string const &filename);
	void	processInput(std::string const &inputFile) const;
};

#endif