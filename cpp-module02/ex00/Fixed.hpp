#ifndef FIXED_HPP
#define FIXED_HPP
#include <string>
#include <iostream>

class Fixed {
private:
	int 				_fixedPointValue;
	static const int    _fractionalBits = 8;         

public:
	Fixed();
	Fixed(const Fixed &other);	// コピーコンストラクタ
	Fixed &operator=(const Fixed &other);   // コピー代入演算子
	~Fixed();

    int  getRawBits(void) const;                        // 生の固定小数点値のゲッター
    void setRawBits(int const raw);    					//生の固定少数点数のセッター
};

#endif
