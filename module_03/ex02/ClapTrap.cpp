#include "ClapTrap.hpp"


ClapTrap :: ClapTrap()
{
    std::cout << "ClapTrap Default constructor called" << "\n";
    this->name = "Default";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap :: ~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << "\n";
}


ClapTrap &ClapTrap :: operator=(ClapTrap const &object)
{
    std::cout << "ClapTrap Copy assignment operator called" << "\n";
    if (this != &object)
    {
        this->name = object.name;
        this->hitPoints = object.hitPoints;
        this->energyPoints = object.energyPoints;
        this->attackDamage = object.attackDamage;
    }
    return *this;
}

ClapTrap :: ClapTrap(ClapTrap const &object)
{
    std::cout << "ClapTrap Copy constructor called" << "\n";
    *this = object;
}

ClapTrap :: ClapTrap(std::string name)
{
    std::cout << "ClapTrap Parameterized constructor called" << "\n";
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

void ClapTrap :: attack(const std::string &target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << "\n";
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " has no energy or hit points left to attack!" << "\n";
    }

}

void ClapTrap :: beRepaired(unsigned int amount)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints--;
        this->hitPoints += amount;
        std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points! Current hit points: " << this->hitPoints << "\n";
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " has no energy or hit points left to be repaired!" << "\n";
    }
}

void ClapTrap :: takeDamage(unsigned int amount)
{
    if (this->hitPoints > 0)
    {
        this->hitPoints -= amount;
        if (this->hitPoints < 0)
            this->hitPoints = 0;
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage! Current hit points: " << this->hitPoints << "\n";
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " has no hit points left to take damage!" << "\n";
    }
}

// int ClapTrap :: getAttackDamage() const
// {
//     return this->attackDamage;
// }