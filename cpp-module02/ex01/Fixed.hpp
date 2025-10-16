#ifndef FIXED_HPP
#define FIXED_HPP
#include <string>
#include <iostream>
#include <cmath>

class Fixed {
private:
	int 				_fixedPointValue;
	static const int    _fractionalBits = 8;         

public:
	Fixed();
	Fixed(const int value); // intからのコピーコンストラクタ（オーバーロード）
	Fixed(const float value); // floatからのコピーコンストラクタ（オーバーロード）
	Fixed(const Fixed &other);	// コピーコンストラクタ

	~Fixed(); // デストラクター

	Fixed& operator=(const Fixed &other);   // コピー代入演算子

    int   getRawBits(void) const;
    void  setRawBits(int const raw);
    float toFloat(void) const;
    int   toInt(void) const;
};
// 出力演算子オーバーロード
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
