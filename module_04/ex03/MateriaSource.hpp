#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

// virtual void learnMateria(AMateria*) = 0;
// virtual AMateria* createMateria(std::string const & type) = 0;

class MateriaSource : public IMateriaSource
{
    private:
    AMateria *store_data[4];
    public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource &obj);
    MateriaSource& operator=(const MateriaSource &obj);
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
    
};



#endif