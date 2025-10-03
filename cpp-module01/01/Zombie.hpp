#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <iostream>

class Zombie {
private:
    std::string _name;

public:
	Zombie();
	Zombie( std:: string name);
	~Zombie();
	void	announce(void);
	void	setName(std::string name);
};
Zombie *ZombieHorde( int N, std::string name );
Zombie *newZombie( std:: string name);
#endif
