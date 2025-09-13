#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "Default constructor called from WrongAnimal class\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "Copy constructor called from WrongAnimal class\n";
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "Copy assignment operator called from WrongAnimal class\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor called from WrongAnimal class\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "The sound from WrongAnimal\n";
}

std::string WrongAnimal::getType() const {
    return this->type;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
    std::cout << "Parameterized constructor called from WrongAnimal class\n";
}

void WrongAnimal::setType(std::string type) {
    this->type = type;
}