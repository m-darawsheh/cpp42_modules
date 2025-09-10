#include "Cat.hpp"

Cat :: Cat()
{
    std::cout << "defalut constructor called from Cat class \n";
    this->type = "Cat";
    this->brain = new Brain();
}

Cat :: ~Cat ()
{
    std::cout << "destructor called from Cat class\n";
    delete brain;
    
}

Cat& Cat::operator=(const Cat &obj)
{
    std::cout << " copy assiment operator form Cat class \n";
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

Cat :: Cat (const Cat&obj)
{
    std :: cout  << "copy constructor form Cat class \n";
    delete brain;
    this->brain = new()
    *this = obj;
}


void Cat::makeSound() const
{
    std::cout << "the sound from Cat \n";
}