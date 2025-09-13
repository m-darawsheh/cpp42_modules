#include "AAnimal.hpp"


AAnimal :: AAnimal () : type("Animal")
{
    std::cout << "defalut constructor called from AAnimal class \n";
}

AAnimal :: ~AAnimal()
{
    std::cout << " destructor form AAnimal class \n";
}

AAnimal& AAnimal::operator=(const AAnimal &obj)
{
    std::cout << " copy assiment operator form AAnimal class \n";
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

AAnimal :: AAnimal (const AAnimal&obj)
{
    std :: cout  << "copy constructor form AAnimal class \n";
    *this = obj;
}

std::string AAnimal::getType() const 
{
    return this->type;
}

void AAnimal::setType(std::string type) {
    this->type = type;
}

AAnimal::AAnimal(std::string type) : type(type) {
    std::cout << "Parameterized constructor called from AAnimal class\n";
}