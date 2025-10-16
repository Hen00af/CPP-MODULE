#include "Fixed.hpp"

/*----------------------*/
/*   コンストラクタの宣言   */
/*----------------------*/
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*----------------------*/
/*コピーコンストラクタの宣言*/
/*----------------------*/
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/*----------------------*/
/*　　コピー代入演算子　　　*/
/*----------------------*/
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return *this;
}

/*----------------------*/
/*　　デストラクターの宣言　　*/
/*----------------------*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const  raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}
