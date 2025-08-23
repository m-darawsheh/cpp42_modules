#ifndef HUMANA_HBB
 #define HUMANA_HBB

#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon *weapon_a;
public:
	HumanA(std::string A_name, Weapon &weapon);
	void attack();
};



 #endif
