#include "MateriaSource.hpp"


MateriaSource :: MateriaSource ()
{
    for (int i = 0 ;  i <  4 ; i++)
    {
        store_data[i] = nullptr;
    }
}

MateriaSource :: ~MateriaSource ()
{
    for (int i = 0 ; i < 4 ; i++)
    {
        if (!store_data[i])
            delete store_data[i];
    }
}

MateriaSource :: MateriaSource(const MateriaSource &obj)
{
    (void) obj;
}


MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{
    (void) obj;
}

void MateriaSource::learnMateria(AMateria* materia)
{
    if (!materia)
    {
        std::cout << "materia is null \n";
        return ;
    }
    for (int i=0 ; i < 4 ; i++)
    {
        if (!store_data[i])
        {
            store_data[i] = materia->clone();
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        if (!store_data[i])
        {
            if (store_data[i]->getType() == type)
            {
                return (store_data[i]->clone());
            }
        }
    }
}