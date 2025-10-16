#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;
	zombie = newZombie("hoge");
	zombie->announce();
	delete zombie;
	randomChump("fuga");
	return 0;	
}
