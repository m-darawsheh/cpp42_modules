#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string name;
    AMateria* inventory[4];
public:
    Character(); // done 
    Character(std::string const & name);// done 
    Character(const Character  & src);// done 
    Character & operator=(const Character  & obj); // done 
    virtual ~Character(); // done 

    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif

