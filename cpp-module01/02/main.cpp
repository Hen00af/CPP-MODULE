#include <iostream>
int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *string_PTR = &str;
	std::string &string_REF = str;

	std::cout << &str << ": " << str << std::endl;
	std::cout << string_PTR << " :" << *string_PTR << std::endl;
	std::cout << &string_REF << " :" << string_REF << std::endl;
	
	return 0;
}
