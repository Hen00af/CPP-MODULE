#include "conversion.hpp"

// 1. デフォルトコンストラクタ
conversion::conversion() {
    std::cout << "Default constructor called" << std::endl; 
}

// 2. コピーコンストラクタ
conversion::conversion(const conversion &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // 代入演算子を呼び出す
}

// 3. 代入演算子
conversion &conversion::operator=(const conversion &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        // ここでメンバ変数のコピー処理を行います
    }
    return *this;
}

// 4. デストラクタ
conversion::~conversion() {
    std::cout << "Destructor called" << std::endl;
}

// private func

void	conversion::_stoi(std::string str) {
	
}

void	conversion::_stof(std::string str) {

}

void	conversion::_stob(std::string str) {
	
}

// public func

void	conversion::convertAndDisplay(std::string str) {

}