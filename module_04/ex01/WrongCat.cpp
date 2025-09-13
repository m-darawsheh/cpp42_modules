#include "WrongCat.hpp"


WrongCat::WrongCat() {
    std::cout << "Default constructor called from WrongCat class\n";
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << "Copy constructor called from WrongCat class\n";
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "Copy assignment operator called from WrongCat class\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "Destructor called from WrongCat class\n";
}

void WrongCat::makeSound() const {
    std::cout << "The sound from WrongCat\n";
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
    std::cout << "Parameterized constructor called from WrongCat class\n";
}