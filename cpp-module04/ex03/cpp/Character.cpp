#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name), count(0)
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character(const Character& other) : name(other.name), count(other.count)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
		{
			inventory[i] = other.inventory[i]->clone();
		}
		else
		{
			inventory[i] = NULL;
		}
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
			{
				delete inventory[i];
			}
			if (other.inventory[i])
			{
				inventory[i] = other.inventory[i]->clone();
			}
			else
			{
				inventory[i] = NULL;
			}
		}
		count = other.count;
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
		}
	}
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		return;
	}
	if (count >= 4)
	{
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			count++;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		return;
	}
	if (inventory[idx] != NULL)
	{
		inventory[idx] = NULL;
		count--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		return;
	}
	if (inventory[idx] != NULL)
	{
		inventory[idx]->use(target);
	}
}

