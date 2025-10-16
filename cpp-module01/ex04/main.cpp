#include "replace.hpp"

int main(int ac,char **av)
{
	std::string str;
	if(ac != 4)
	{
		std::cout << "Error: invalid number of arguments\n" << "Usage: ./replace <filename> <string1> <string2>" <<std::endl;
		return -1;
	}
	Replace s(av[1],av[2],av[3]);
	s.replace();
	return 0;
}
