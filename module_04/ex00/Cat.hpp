#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
    Cat();
    ~Cat();
    Cat(const Cat &obj);
    Cat &operator=(const Cat &obj);
    void makeSound() const;
    Cat(std::string type);
};


#endif