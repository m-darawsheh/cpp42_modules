#include "Contact.hpp"
#include "PhoneBook.hpp"

int main (void)
{
	std::string user_input;
	std::string ADD = "ADD";
	std::string SEARCH = "SEARCH";
	std::string EXIT = "EXIT";
	PhoneBook phonebook;

	std::cout << "Welecom to phonebook 😁" << "\n";
	while (true)
	{
		std:: cout << "You have just three commands 'ADD' 'SEARCH' 'EXIT'" << "\n";
		std:: cout << "please enter one of these commands :  ";
        if (!std::getline(std::cin, user_input)) {
            std::cout << "\nEOF reached or input error. Exiting.\n";
            break;
        }
		for (char &c : user_input)
		{
			c = toupper(c);
		}
		if (ADD.compare(user_input) == 0)
		{
			phonebook.addContact();
		}
		else if (SEARCH.compare(user_input) == 0)
		{
			phonebook.searchContact();
		}
		else if (EXIT.compare(user_input) == 0)
		{
			std::cout << "\033[35mExiting the phonebook. Goodbye! 👋\033[0m" << "\n";
			break;
		}
		else
		{
			std::cout << "Invalid command, please try again." << "\n";
		}
	}
	return 0;

}

