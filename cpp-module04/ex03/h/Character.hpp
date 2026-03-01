#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Icharacter.hpp"
#include "Aclass.hpp"
#include <string>

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[4];
		int count;
	public:
		Character(std::string const & name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		virtual ~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif

