#include "Zombie.hpp"

Zombie:: Zombie()
{
	this->name = "";
}

Zombie::~Zombie()
{
	std::cout<< this->name << " is dead" << "\n";
}

void Zombie::announce(void)
{
	std::cout<<this->name<<": BraiiiiiiinnnzzzZ..." << "\n";
}

void Zombie::setName(std::string name)
{
	this->name = name;
}