#include <iostream>
#include "r_Fixed.hpp?

int main()
{
	std::cout << "____ base tset ____" << std::endl;
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2) );
	Fixed c(10);
	Fixed d(42.42f);
	Fixed e(b);
	Fixed f;
	f = d; // Copy assignment
	
	std::cout << "/n ---- 算術演算テスト----" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "f: " << f << std::endl;


	std::cout << "/n ---- 比較演算子テスト----" << std::endl;
	
	std::cout <<  << std::endl;
}



