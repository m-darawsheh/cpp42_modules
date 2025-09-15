#include "Character.hpp"

Character::Character() : name("default") {
    for (int i = 0; i < 4; i++) {
        inventory[i] = 0;
    }
}

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = 0;
    }
}

Character& Character::operator=(const Character  & obj) {
    if (this != &obj)
    {
        this->name = obj.name;
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i]) {
                delete this->inventory[i];
            }
            if (obj.inventory[i]) {
                this->inventory[i] = obj.inventory[i]->clone();
            } else {
                this->inventory[i] = 0;
            }
        }
    }
    return *this;
}

Character::Character(const Character  & src) : name(src.name) {
    for (int i = 0; i < 4; ++i)
    {
        if (src.inventory[i])
            inventory[i] = src.inventory[i]->clone();
        else
            inventory[i] = 0;
    }
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (inventory[i]) {
            delete inventory[i];
        }
    }
}


    // std::string const & getName() const;
    // void equip(AMateria* m);
    // void unequip(int idx);
    // void use(int idx, ICharacter& target);

std::string const & Character::getName() const {
    return this->name;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4)
    {
        std::cout << "out of range\n";
    }
    inventory[idx] = 0;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
    std::cout<<"full inventory \n";
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 4 || idx < 0)
        return;
    if (inventory[idx] != NULL)
        inventory[idx]->use(target);
}