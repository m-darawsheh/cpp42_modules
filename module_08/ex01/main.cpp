#include "Span.hpp"

int main()
{
    {
        Span sp = Span(5);
        sp.addNumber(0);
        sp.addNumber(-1);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        Span s(4);
        try
        {
            s.addNumber(6);
            s.addNumber(3);
            s.addNumber(17);
            s.addNumber(9);
            s.addNumber(11);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            
            std::vector<int> NEW ;
            NEW .push_back (1);
            NEW .push_back (2);
            NEW .push_back (3);
            NEW .push_back (4);
            s.addNumber(NEW.begin(), NEW.end());
            std::cout << s.shortestSpan() << std::endl;
            std::cout << s.longestSpan() << std::endl;
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

return 0;
}