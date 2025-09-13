#ifndef Cat_HPP
#define Cat_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain* brain;
    public:
    Cat();
    ~Cat();
    Cat(const Cat &obj);
    Cat &operator=(const Cat &obj);
    void makeSound() const;
    Brain* getBrain() const;
    Cat(std::string type);
};


#endif