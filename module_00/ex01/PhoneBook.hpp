#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
	Contact contact[8];
	int index_of_contacts;
	int oldest_contact_index;
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
	std::string shortCutContact(std::string str);
};

#endif
