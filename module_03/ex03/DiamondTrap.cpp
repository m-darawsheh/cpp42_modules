#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), name("default")
{
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name << " default constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
    std::cout << "DiamondTrap " << this->name << " copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->name = obj.name;
        this->ClapTrap::name = obj.ClapTrap::name;
        this->hitPoints = obj.hitPoints;
        this->energyPoints = obj.energyPoints;
        this->attackDamage = obj.attackDamage;
    }
    return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj)
{
    std::cout << "DiamondTrap " << this->name << " copy constructor called" << std::endl;
    *this = obj;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name(name)
{
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << this->name << " constructor called" << std::endl;
}


void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << this->ClapTrap::name << std::endl;
}