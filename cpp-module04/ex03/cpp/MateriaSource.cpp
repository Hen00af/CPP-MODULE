#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() : count(0)
{
	for (int i = 0; i < 4; i++)
	{
		learned[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) : count(other.count)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.learned[i])
		{
			learned[i] = other.learned[i]->clone();
		}
		else
		{
			learned[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (learned[i])
			{
				delete learned[i];
			}
			if (other.learned[i])
			{
				learned[i] = other.learned[i]->clone();
			}
			else
			{
				learned[i] = NULL;
			}
		}
		count = other.count;
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (learned[i])
		{
			delete learned[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
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
		if (learned[i] == NULL)
		{
			learned[i] = m->clone();
			count++;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (learned[i] != NULL && learned[i]->getType() == type)
		{
			return learned[i]->clone();
		}
	}
	return NULL;
}

