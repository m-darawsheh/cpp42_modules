#include <string>
#include <iostream>
class Contact
{
	private :
		std::string  first_name;
		std::string  last_name;
		std::string  nickname;
		std::string  phone_number;
		std::string  darkest_secret;
	public:
	Contact()
	{
		first_name = "";
		last_name = "";
		nickname = "";
		phone_number = "";
		darkest_secret = "";
	};
	void setFirstName(const std::string& name) { first_name = name; }
	void setLastName(const std::string& name) { last_name = name; }
	void setNickname(const std::string& name) { nickname = name; }
	void setPhoneNumber(const std::string& number) { phone_number = number; }
	void setDarkestSecret(const std::string& secret) { darkest_secret = secret; }

	std::string getFirstName() const { return first_name; }
	std::string getLastName() const { return last_name; }
	std::string getNickname() const { return nickname; }
	std::string getPhoneNumber() const { return phone_number; }
	std::string getDarkestSecret() const { return darkest_secret; }
};
class PhoneBook
{
	private:
	Contact contact[8];
	int index_of_contacts;
	public:
	PhoneBook()
	{
		index_of_contacts = 0;
	}
	void addContact();
	void searchContact();
};

void PhoneBook ::addContact()
{
	if (index_of_contacts < 8)
	{
		while (true)
		{
			std::cout << "Please enter first name: ";
			std::getline(std::cin, contact[index_of_contacts].getFirstName());
			if (!contact[index_of_contacts].getFirstName().empty())
				break;
			std::cout << "First name cannot be empty. Please try again." << std::endl;
		}
	}
	else
	{
		// here must be delete the first contact and add the new one
	}
}

void PhoneBook ::searchContact()
{
	// here must be search for a contact
}

int main (void)
{
	//object for Contact;
	//object for PhoneBook;
	std::string user_input;
	std::string ADD = "ADD";
	std::string SEARCH = "SEARCH";
	std::string EXIT = "EXIT";

	std::cout << "Welecom to phonebook 😁" << "\n";
	while (true)
	{
		std:: cout << "You have just three commands 'ADD' 'SEARCH' 'EXIT'" << "\n";
		std:: cout << "-- ADD for add new contact --" << "\n";
		std:: cout << "-- SEARCH for search a specific contact --" << "\n";
		std:: cout << "-- EXIT for exit from program --" << "\n";
		std:: cout << "please enter one of these commands ";
		std:: getline(std::cin, user_input);

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
			break;
		}
		else
		{
			std::cout << "Invalid command, please try again." << "\n";
		}
	}
	return 0;

}

