#include "HumanB.hpp"


void HumanB:: setWeapon(Weapon &weapon)
{
	weapon_b = &weapon;
}


void HumanB :: attack()
{
	std::cout << name << " : attacks with their" << weapon_b->getType();
}

HumanB :: HumanB(std::string name_of_human)
{
	name = name_of_human;
} 