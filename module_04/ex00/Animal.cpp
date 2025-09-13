#include "Animal.hpp"


Animal :: Animal () : type("Animal")
{
    std::cout << "defalut constructor called from Animal class \n";
}

Animal :: ~Animal()
{
    std::cout << " destructor form Animal class \n";
}

Animal& Animal::operator=(const Animal &obj)
{
    std::cout << " copy assiment operator form Animal class \n";
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

Animal :: Animal (const Animal&obj)
{
    std :: cout  << "copy constructor form Animal class \n";
    *this = obj;
}

void Animal:: makeSound() const
{
    std::cout << " the sound from animal\n";
}

std::string Animal::getType() const 
{
    return this->type;
}


void Animal::setType(std::string type) {
    this->type = type;
}


Animal::Animal(std::string type) : type(type) {
    std::cout << "Parameterized constructor called from Animal class\n";
}
