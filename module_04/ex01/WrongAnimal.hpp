#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    protected:
        std::string type;
    
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        ~WrongAnimal();
        WrongAnimal(std::string type);
        void setType(std::string type);
        std::string getType() const;
        void makeSound() const;
};

#endif