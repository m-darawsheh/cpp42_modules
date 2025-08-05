#include <string>
#include <iostream>
#include <cctype>
class Contact
{
	private :
		std::string  first_name;
		std::string  last_name;
		std::string  nickname;
		std::string  phone_number;
		std::string  darkest_secret;
		bool is_empty;
		int index_of_contact;
	public:
	Contact()
	{
		is_empty = true;
		first_name = "";
		last_name = "";
		nickname = "";
		phone_number = "";
		darkest_secret = "";
		index_of_contact = 0;
	};
	void setFirstName(const std::string& name) { first_name = name; }
	void setLastName(const std::string& name) { last_name = name; }
	void setNickname(const std::string& name) { nickname = name; }
	void setPhoneNumber(const std::string& number) { phone_number = number; }
	void setDarkestSecret(const std::string& secret) { darkest_secret = secret; }
	void setIsEmpty(bool empty) { is_empty = empty; }
	void setIndexOfContact(int index) { index_of_contact = index; }

	std::string& getFirstName()  { return first_name; }
	std::string& getLastName()  { return last_name; }
	std::string& getNickname()  { return nickname; }
	std::string& getPhoneNumber()  { return phone_number; }
	std::string& getDarkestSecret()  { return darkest_secret; }
	bool& getIsEmpty()  { return is_empty; }
	int& getIndexOfContact()  { return index_of_contact; }
};
class PhoneBook
{
	private:
	Contact contact[8];
	int index_of_contacts;
	int oldest_contact_index; // This can be used to track the oldest contact for replacement
	public:
	PhoneBook()
	{
		index_of_contacts = 0;
		oldest_contact_index = 0;
	}
	void addPersonRightWay(int index);
	void addPersonReplace(int index);
	void addContact();
	void searchContact();
};

void PhoneBook ::addPersonRightWay(int index)
{
	while (true)
	{
		std::cout << "Please enter first name: ";
		std::getline(std::cin, contact[index].getFirstName());
		if (!contact[index].getFirstName().empty())
			break;
		std::cout << "First name cannot be empty. Please try again." << "\n";
		contact[index].setFirstName("");
	}
	while (true)
	{
		std::cout << "Please enter last name: ";
		std::getline(std::cin, contact[index].getLastName());
		if (!contact[index].getLastName().empty())
			break;
		std::cout << "Last name cannot be empty. Please try again." << "\n";
		contact[index].setLastName("");
	}
	while (true)
	{
		std::cout << "Please enter nickname: ";
		std::getline(std::cin, contact[index].getNickname());
		if (!contact[index].getNickname().empty())
			break;
		std::cout << "Nickname cannot be empty. Please try again." << "\n";
		contact[index].setNickname("");
	}
	while (true)
	{
		std::cout << "Please enter phone number: ";
		std::getline(std::cin, contact[index].getPhoneNumber());
		std::string temp = contact[index].getPhoneNumber();
		std::cout << "the temp after get the value from class: " << temp << "\n";
		if (!temp.empty() && temp.length() == 10)
		{
			for (char c : temp)
			{
				if (!isdigit(c))
				{
					std::cout << "Invalid character in phone number. Please enter a 10-digit phone number." << "\n";
					temp = "";
					break;
				}
			}

		}
		if (!temp.empty())
		{
			std::cout << "enter the second break" << "\n";
			contact[index].setPhoneNumber(temp);
			break;
		}
		std::cout << "Invalid phone number. Please enter a 10-digit phone number." << "\n";
		contact[index].setPhoneNumber("");
	}
	while (true)
	{
		std::cout << "Please enter darkest secret: ";
		std::getline(std::cin, contact[index].getDarkestSecret());
		if (!contact[index].getDarkestSecret().empty())
			break;
		std::cout << "Darkest secret cannot be empty. Please try again." << "\n";
		contact[index].setDarkestSecret("");
	}
}
void PhoneBook ::addPersonReplace(int index)
{
	std::cout << "You have reached the maximum number of contacts. Replacing oldest contact." << "\n";
	addPersonRightWay(index);
}

void PhoneBook ::addContact()
{
	if (index_of_contacts < 8)
	{
		addPersonRightWay(index_of_contacts);
		contact[index_of_contacts].setIsEmpty(false);
		contact[index_of_contacts].setIndexOfContact(index_of_contacts);
		index_of_contacts++;
	}
	else
	{
		addPersonReplace(oldest_contact_index);
		contact[oldest_contact_index].setIsEmpty(false);
		contact[oldest_contact_index].setIndexOfContact(oldest_contact_index);
		oldest_contact_index = (oldest_contact_index + 1) % 8;
	}
}

void PhoneBook ::searchContact()
{
	int search_index = 0;
	int input_index = 0;
	while (!contact[search_index].getIsEmpty())
	{
		std:: cout << "index:" << contact[search_index].getIndexOfContact() << "\n";
		std::cout << "First Name: " << contact[search_index].getFirstName() << "\n";
		std::cout << "Last Name: " << contact[search_index].getLastName() << "\n";
		std::cout << "Nickname: " << contact[search_index].getNickname() << "\n";
		std::cout << "Phone Number: " << contact[search_index].getPhoneNumber() << "\n";
		std::cout << "Darkest Secret: " << contact[search_index].getDarkestSecret() << "\n";
		break;
	}
	std::cout << "Please enter the index of the contact you want to search" << "\n";
	std::cin >> input_index;
}

int main (void)
{
	//object for Contact;
	//object for PhoneBook;
	std::string user_input;
	std::string ADD = "ADD";
	std::string SEARCH = "SEARCH";
	std::string EXIT = "EXIT";
	PhoneBook phonebook;

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
			phonebook.addContact();
		}
		else if (SEARCH.compare(user_input) == 0)
		{
			// SEARCH command
			phonebook.searchContact();
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

