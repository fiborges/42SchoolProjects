#include "Weapon.hpp"

Weapon::Weapon()
{
	
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
	
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

std::string Weapon::getType(void) const
{
	return (this->type);
}


Weapon& Weapon::operator=(const Weapon& right)
{
	if (this == &right)
		return (*this);
	this->type = right.type;
	return (*this);
}