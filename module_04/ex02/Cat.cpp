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
        delete brain;
        this->brain = new Brain(*obj.brain);
        this->type = obj.type;
    }
    return *this;
}

Cat :: Cat (const Cat&obj)
{
    std :: cout  << "copy constructor form Cat class \n";
    this->brain = new Brain(*obj.brain);
    this->type = obj.type;
}


void Cat::makeSound() const
{
    std::cout << "the sound from Cat \n";
}

Brain* Cat::getBrain() const
{
    return this->brain;
}
Cat::Cat(std::string type)
{
    std::cout << "parameterized constructor called from Cat class \n";
    this->type = type;
    this->brain = new Brain();
}