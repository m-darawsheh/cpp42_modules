#include "helpers.hpp"

Base *generate(void)
{
    std::srand(std::time(0));
    int num = (std::rand() % 3) + 1;
    Base *result = NULL;
    switch (num)
    {
        case 1:
            result = new A;
            break;
        case 2:
            result = new B;
            break;
        case 3:
            result = new C;
            break;
        default:
            result = NULL;
            break;
    }
    return result;
}

void identify(Base* p)
{
    A* test = dynamic_cast<A*>(p);
    if (!test)
    {
        B* test = dynamic_cast<B*>(p);
        if (!test)
        {
            C* test = dynamic_cast<C*>(p);
            if(test)
            {
                std::cout <<"the type is C \n"; 
            }
        }
        else
        {
            std::cout <<"the type is B \n";
        }
    }
    else
    {
        std::cout<<"the type is A \n";
    }
    return;

}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout<<"the type is A \n";
    }
    catch(const std::exception& e)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout<<"the type is B \n";
        }
        catch(const std::exception& e)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout<<"the type is C \n";
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
        
    }
    return;
}