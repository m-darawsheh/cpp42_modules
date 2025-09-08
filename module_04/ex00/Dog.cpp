#include "Dog.hpp"

Dog :: Dog()
{
    std::cout << "defalut constructor called from Dog class \n";
    this->type = "Dog";
}
Dog :: ~Dog ()
{
    std::cout << "destructor called from Dog class\n";
}
Dog& Dog::operator=(const Dog &obj)
{
    std::cout << " copy assiment operator form Dog class \n";
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}
Dog :: Dog (const Dog&obj)
{
    std :: cout  << "copy constructor form Dog class \n";
    *this = obj;
}

void Dog::makeSound() const
{
    std::cout << "the sound from Dog \n";
}