
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form form;
        Bureaucrat test2("name", 70);
        test2.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}