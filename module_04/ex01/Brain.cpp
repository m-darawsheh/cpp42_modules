#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "default constuctor called from Brain class\n";
    for(int i = 0; i <  100 ; i++)
    {
        ideas[i] = "";
    }
}

Brain::~Brain()
{
    std::cout<<"destructor called from Brain class\n";
}

Brain::Brain(const Brain &copy)
{
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = copy.ideas[i];
    }
    std::cout << "copy constructor called from Brain class\n";
}

Brain &Brain::operator=(const Brain &copy)
{
    std::cout << "copy assignment operator called from Brain class\n";
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = copy.ideas[i];
        }
    }
    return *this;
}