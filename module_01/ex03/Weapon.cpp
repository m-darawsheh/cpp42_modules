#include"Weapon.hpp"

Weapon::Weapon(std::string wepon_type)
{
	type = wepon_type;
}


Weapon::Weapon()
{
	type = "";
}


const std::string& Weapon :: getType()
{
	return type;
}

void Weapon :: setType (std::string new_type)
{
	type = new_type;
}

