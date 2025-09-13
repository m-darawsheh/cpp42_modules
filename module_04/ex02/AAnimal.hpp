#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
    protected:
        std::string type;
    public:
    AAnimal();
    virtual ~AAnimal();
    AAnimal(const AAnimal &obj);
    AAnimal &operator=(const AAnimal &obj);
    virtual void makeSound() const = 0;
    std::string getType() const;
    void setType(std::string type);
    AAnimal(std::string type);
};

#endif