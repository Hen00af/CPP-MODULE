#ifndef FIXED_HPP
#define FIXED_HPP
#include <string>
#include <iostream>
#include <cmath>

//operatorは演算子をクラスに対して意味付けする関数

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

	//　比較演算子
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

	// 算術演算子
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	
	// operator+ : 2つのFixedオブジェクトを加算し、新しいFixedを返す
	// operator++ : 値を1/256ずつインクリメント（固定小数点の1単位）

	//　インクリメント・デクリメント
	Fixed &operator++();	// prefix
	Fixed operator++(int);	// postfix
	Fixed &operator--();
	Fixed operator--(int);


	// min / max
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

    int   	getRawBits(void) const;
    void  	setRawBits(int const raw);
    float 	toFloat(void) const;
    int   	toInt(void) const;
};

// 出力演算子オーバーロード
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
