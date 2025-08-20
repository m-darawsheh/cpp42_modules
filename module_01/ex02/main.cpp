#include <iostream>
#include <string>


int main()
{
	std:: string name = "HI THIS IS BRAIN";
	std:: string* stringPTR = &name;
	std:: string& stringREF = name;
	std::cout << "The memory address of the string variable: " << &name << "\n";
	std::cout << "The memory address held by stringPTR: " << stringPTR << "\n";
	std::cout << "The memory address held by stringREF: " << &stringREF << "\n";

	std::cout << "The value of the string variable: " << name << "\n";
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << "\n";
	std::cout << "The value pointed to by stringREF: " << stringREF << "\n";

}
