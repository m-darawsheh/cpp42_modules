#include <string>
#include <iostream>
class Contact
{
	private :

	public:
};
class PhoneBook
{
	private:
	Contact contacts[8];
	public:

};

int main (void)
{
	//object for Contact;
	//object for PhoneBook;
	std::string user_input;
	std::string ADD = "ADD";
	std::string SEARCH = "SEARCH";
	std::string EXIT = "EXIT";

	std::cout << "Welecom to phonebook 😁" << "\n";
	std:: cout << "You have just three commands 'ADD' 'SEARCH' 'EXIT'" << "\n";
	std:: cout << "-- ADD for add new contact --" << "\n";
	std:: cout << "-- SEARCH for search a specific contact --" << "\n";
	std:: cout << "-- EXIT for exit from program --" << "\n";
	std:: cout << "please enter one of these commands ";
	std:: cin >> user_input;

	if (ADD.compare(user_input) == 0)
	{
		// ADD command
	}
	else if (SEARCH.compare(user_input) == 0)
	{
		// SEARCH command
	}
	else if (EXIT.compare(user_input) == 0)
	{
		// EXIT command
		exit(0);
	}
	else
	{
		// please enter one of these three command ADD SEARCH EXIT
	}
	return 0;

}

