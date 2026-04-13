#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <string>

class Conversion {
public:

	// CALONICAL FORM
	conversion();
	~conversion();
	conversion &operator=(const conversion other);
	conversion(conversion other);

    // 表示用関数
    void convertAndDisplay(std::string str);

private:
    // 変換担当（内部で使う）
    int    _stoi(std::string str);
    float  _stof(std::string str);
    double _stod(std::string str);

    // 表示担当（内部で使う）
    // あなたが書いた print(this->others) の代わりです
    void   _printAll(double d);
};

#endif