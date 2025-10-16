#include "Harl.hpp"

int main(int ac,char **av)
{
	Harl	harl;

	if(ac != 2){
		std::cout << "YOU SHOULD PUT ONLY 1 ARGMENT!!!";
		return 0; 
	}
	harl.filter(av[1]);
	return (EXIT_SUCCESS);
}
