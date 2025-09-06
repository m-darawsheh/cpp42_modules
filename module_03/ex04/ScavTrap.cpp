#include "ScavTrap.hpp"

ScavTrap :: ScavTrap(): ClapTrap()
{
    std::cout << "ScavTrap Default constructor called" << "\n";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap :: ~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << "\n";
}


ScavTrap & ScavTrap::operator=(const ScavTrap &obj)
{
    std::cout << "ScavTrap Copy assignment operator called" << "\n";
    if (this != &obj)
    {
        this->name = obj.name;
        this->hitPoints = obj.hitPoints;
        this->energyPoints = obj.energyPoints;
        this->attackDamage = obj.attackDamage;
    }
    return (*this);
}

ScavTrap :: ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
    std::cout << "ScavTrap Copy constructor called" << "\n";
    *this = obj;
}


ScavTrap :: ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << "ScavTrap Parameterized constructor called" << "\n";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

void ScavTrap :: guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << "\n";
}

void ScavTrap :: attack(const std::string &target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << "\n";
        this->energyPoints--;
    }
    else
        std::cout << "ScavTrap " << this->name << " has no energy or hit points left to attack." << "\n";
}
