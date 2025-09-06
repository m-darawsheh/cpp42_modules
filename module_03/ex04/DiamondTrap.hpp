#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string name;
public:
    DiamondTrap();
    ~DiamondTrap();
    DiamondTrap(const DiamondTrap &obj);
    DiamondTrap &operator=(const DiamondTrap &obj);
    DiamondTrap(std::string name);
    void attack(const std::string &target);
    void whoAmI();
};

#endif