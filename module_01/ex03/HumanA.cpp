#include "HumanA.hpp"

HumanA :: HumanA(std::string A_name, Weapon &weapon)
{
	name = A_name;
	weapon_a = &weapon;
}
void HumanA :: attack()
{
	std::cout << name << " : attacks with their" << weapon_a->getType();
}
