#include "Fixed.hpp"

/*----------------------*/
/*   コンストラクタの宣言   */
/*----------------------*/
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*---------------------------------------*/
/*コピーコンストラクタの宣言のオーバーロード定義*/
/*---------------------------------------*/
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(value * (1 << _fractionalBits));
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

float Fixed::toFloat(void) const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

// --- 比較演算子 ---
bool Fixed::operator>(const Fixed &other) const { return this->_fixedPointValue > other._fixedPointValue; }
bool Fixed::operator<(const Fixed &other) const { return this->_fixedPointValue < other._fixedPointValue; }
bool Fixed::operator>=(const Fixed &other) const { return this->_fixedPointValue >= other._fixedPointValue; }
bool Fixed::operator<=(const Fixed &other) const { return this->_fixedPointValue <= other._fixedPointValue; }
bool Fixed::operator==(const Fixed &other) const { return this->_fixedPointValue == other._fixedPointValue; }
bool Fixed::operator!=(const Fixed &other) const { return this->_fixedPointValue != other._fixedPointValue; }

// --- 算術演算子 ---
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed res;
	res._fixedPointValue = this->_fixedPointValue + other._fixedPointValue;
	return res;
}
Fixed Fixed::operator-(const Fixed &other) const {
	Fixed res;
	res._fixedPointValue = this->_fixedPointValue - other._fixedPointValue;
	return res;
}
Fixed Fixed::operator*(const Fixed &other) const {
	Fixed res;
	long tmp = (long)this->_fixedPointValue * (long)other._fixedPointValue;
	res._fixedPointValue = (int)(tmp >> _fractionalBits);
	return res;
}
Fixed Fixed::operator/(const Fixed &other) const {
	Fixed res;
	long tmp = ((long)this->_fixedPointValue << _fractionalBits) / (long)other._fixedPointValue;
	res._fixedPointValue = (int)tmp;
	return res;
}

// --- インクリメント・デクリメント ---
Fixed &Fixed::operator++() { // prefix
	++this->_fixedPointValue;
	return *this;
}
Fixed Fixed::operator++(int) { // postfix
	Fixed tmp(*this);
	++this->_fixedPointValue;
	return tmp;
}
Fixed &Fixed::operator--() { --this->_fixedPointValue; return *this; }
Fixed Fixed::operator--(int) { Fixed tmp(*this); --this->_fixedPointValue; return tmp; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	return (a < b ? a : b);
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	return (a > b ? a : b);
}

// --- << 演算子オーバーロード --- ???
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

