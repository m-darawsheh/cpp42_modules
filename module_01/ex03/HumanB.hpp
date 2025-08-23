#ifndef HUMANB_HBB
 #define HUMANB_HBB

#include "Weapon.hpp"

 class HumanB
 {
	private:
	std::string name;
	Weapon *weapon_b;
	public:
	HumanB(std::string name_of_human);
	void attack();
	void setWeapon(Weapon &weapon);

 };

 #endif
