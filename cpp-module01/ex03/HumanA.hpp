#ifndef HumanA_HPP 
#define HumanA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA {
	private :
		std::string name;
		Weapon& weapon;
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void attack();
}; 

#endif
