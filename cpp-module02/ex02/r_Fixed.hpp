#paragma onece
#define FIXED_HPP
#include <string>
#include <iostream>
#include <cmath>

class Fixed{
	private:
		int			_fizPointValue;
		static const int	_frctionalBits;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		~Foxed();

		Fixed& operator=(const Fixed &other);

		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
}
