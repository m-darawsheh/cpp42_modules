#include "Dog.hpp"

Dog :: Dog()
{
    std::cout << "defalut constructor called from Dog class \n";
    this->type = "Dog";
    this->brain = new Brain();
}
Dog :: ~Dog ()
{
    std::cout << "destructor called from Dog class\n";
    delete brain;
}

Dog& Dog::operator=(const Dog &obj)
{
    std::cout << " copy assiment operator form Dog class \n";
    if (this != &obj)
    {
        delete brain;
        this->brain = new Brain(*obj.brain);
        this->type = obj.type;
    }
    return *this;
}

Dog :: Dog (const Dog&obj)
{
    std :: cout  << "copy constructor form Dog class \n";
    this->brain = new Brain(*obj.brain);
    this->type = obj.type;
}

void Dog::makeSound() const
{
    std::cout << "the sound from Dog \n";
}
Brain* Dog::getBrain() const
{
    return this->brain;
}
Dog::Dog(std::string type)
{
    std::cout << "parameterized constructor called from Dog class \n";
    this->type = type;
    this->brain = new Brain();
}