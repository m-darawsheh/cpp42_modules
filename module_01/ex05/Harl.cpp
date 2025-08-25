#include "Harl.hpp"
#include <iostream>


void Harl::debug()
{
    std::cout << "[ DEBUG ]" << "\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << "\n";
}

void Harl::info()
{
    std::cout << "[ INFO ]" << "\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << "\n";
}

void Harl::warning()
{
    std::cout << "[ WARNING ]" << "\n";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been a good customer for years!" << "\n";
}

void Harl::error()
{
    std::cout << "[ ERROR ]" << "\n";
    std::cout << "This is unacceptable! I want to speak to the manager now!" << "\n";
}



void Harl::complain(std::string level)
{
	std::string dict[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptrs[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (level == dict[i])
		{
			(this->*ptrs[i])();
			return;
		}
	}
}




// void (*test) (void) = &error

// void (Harl::*test[4]) (void) ;
