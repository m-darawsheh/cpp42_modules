#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        store_data[i] = 0; 
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (store_data[i]) {
            delete store_data[i];
            store_data[i] = 0;
        }
    }
}

MateriaSource::MateriaSource(const MateriaSource &obj) {
    for (int i = 0; i < 4; i++) {
        if (obj.store_data[i])
            store_data[i] = obj.store_data[i]->clone();
        else
            store_data[i] = 0;
    }
}

MateriaSource & MateriaSource::operator=(const MateriaSource &obj) {
    if (this != &obj) {
        for (int i = 0; i < 4; i++) {
            if (store_data[i]) {
                delete store_data[i];
                store_data[i] = 0;
            }
            if (obj.store_data[i])
                store_data[i] = obj.store_data[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
    if (!materia) {
        std::cout << "materia is null\n";
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!store_data[i]) {
            store_data[i] = materia; 
            return; 
        }
    }
    std::cout << "slots full\n";
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (store_data[i] && store_data[i]->getType() == type)
            return store_data[i]->clone();
    }
    return 0;
}