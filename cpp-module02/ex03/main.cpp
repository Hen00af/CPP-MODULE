#include <iostream>
#include "Fixed.hpp"

// int main( void ) {
// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;
// return 0;
// }

int main(void) {
    std::cout << "----- 基本動作テスト -----" << std::endl;
    Fixed a;                   // Default constructor
    Fixed const b(Fixed(5.05f) * Fixed(2)); // Float * Int
    Fixed c(10);               // Int constructor
    Fixed d(42.42f);           // Float constructor
    Fixed e(b);                // Copy constructor
    Fixed f;                   // Assignment test target
    f = d;                     // Copy assignment

    std::cout << "\n----- 出力演算子 (<<) テスト -----" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "f: " << f << std::endl;

    std::cout << "\n----- 算術演算子テスト -----" << std::endl;
    std::cout << "b + c = " << (b + c) << std::endl;
    std::cout << "c - b = " << (c - b) << std::endl;
    std::cout << "b * c = " << (b * c) << std::endl;
    std::cout << "c / b = " << (c / b) << std::endl;

    std::cout << "\n----- 比較演算子テスト -----" << std::endl;
    std::cout << "a < b : " << (a < b) << std::endl;
    std::cout << "a > b : " << (a > b) << std::endl;
    std::cout << "b == e : " << (b == e) << std::endl;
    std::cout << "b != c : " << (b != c) << std::endl;
    std::cout << "c >= b : " << (c >= b) << std::endl;
    std::cout << "b <= e : " << (b <= e) << std::endl;

    std::cout << "\n----- インクリメント・デクリメントテスト -----" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "++a = " << ++a << std::endl;  // 前置
    std::cout << "a++ = " << a++ << std::endl;  // 後置
    std::cout << "a = " << a << std::endl;
    std::cout << "--a = " << --a << std::endl;
    std::cout << "a-- = " << a-- << std::endl;
    std::cout << "a = " << a << std::endl;

    std::cout << "\n----- min / max テスト -----" << std::endl;
    std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
    std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;

    std::cout << "\n----- getRawBits / setRawBits テスト -----" << std::endl;
    std::cout << "a.getRawBits(): " << a.getRawBits() << std::endl;
    a.setRawBits(2560); // 10 << 8
    std::cout << "a.setRawBits(2560) → toFloat(): " << a.toFloat() << std::endl;

    std::cout << "\n----- toInt / toFloat テスト -----" << std::endl;
    std::cout << "d.toInt(): " << d.toInt() << std::endl;
    std::cout << "d.toFloat(): " << d.toFloat() << std::endl;

    std::cout << "\n----- 総合テスト: max(a, b) == a ? a : b -----" << std::endl;
    std::cout << (Fixed::max(a, b) == a ? a : b) << std::endl;

    std::cout << "\n----- 終了 -----" << std::endl;
    return 0;
}
