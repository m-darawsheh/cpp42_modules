#include "PhoneBook.hpp"

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
		if (temp.length() != 10)
		{
			std::cout << "Invalid phone number. Please enter a 10-digit phone number." << "\n";
			contact[index].setPhoneNumber("");
			continue;
		}
		long num = std::stol(temp);
		temp = std::to_string(num);
		for (char c : temp)
		{
			if (c == '-')
			{
				std::cout << "Invalid character in phone number. Please enter a 10-digit phone number." << "\n";
				temp = "";
				break;
			}
		}
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
	std::cout << "\033[92mContact added successfully 💯\033[0m" << "\n";
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

std::string PhoneBook ::shortCutContact(std::string str)
{
    if (str.length() > 10)
    {
        std::string temp = str.substr(0, 9);
        return temp + ".";
    }
    return str;
}

void PhoneBook ::searchContact()
{
	int search_index = 0;
	int input_index = 0;
	if (index_of_contacts == 0)
	{
		std::cout << "\033[31mNo contacts available. Please add contacts first.\033[0m" << "\n";
		return;
	}
	std ::cout << "| " << std::setw(10) << "Index"
			   << " | " << std::setw(10) << "First Name"
			   << " | " << std::setw(10) << "Last Name"
			   << " | " << std::setw(10) << "Nickname"
			   << " |" << std::endl;
	std ::cout << "-----------------------------------------------------" << std ::endl;
	while (search_index < 8 && !contact[search_index].getIsEmpty())
	{
		std::cout << "| " << std::setw(10) << std::right << "index:" << contact[search_index].getIndexOfContact() << " | " << std::setw(10) << std::right << shortCutContact(contact[search_index].getFirstName()) << " | " << std::setw(10) << std::right << shortCutContact(contact[search_index].getLastName()) << " | " << std::setw(10) << std::right << shortCutContact(contact[search_index].getNickname()) << " | " << "\n";
		search_index++;
	}
	while (true)
	{
		std::cout << "Please enter the index of the contact you want to search: ";
		std::cin >> input_index;
		if (input_index < 0 || input_index > search_index - 1)
		{
			std::cout << "Invalid index. Please try again." << "\n";
			input_index = 0;
			std::cin.clear();
			std::cin.ignore(MAX_LIMIT, '\n');
			continue;
		}
		break;
	}
	std::cout << "First Name: " << contact[input_index].getFirstName() << "\n";
	std::cout << "Last Name: " << contact[input_index].getLastName() << "\n";
	std::cout << "Nickname: " << contact[input_index].getNickname() << "\n";
	std::cout << "Phone Number: " << contact[input_index].getPhoneNumber() << "\n";
	std::cout << "Darkest Secret: " << contact[input_index].getDarkestSecret() << "\n";
	std::cout << "\033[34mPress enter to continue...\033[0m";
	std::cin.ignore(MAX_LIMIT, '\n');
	std::cin.get();
}
