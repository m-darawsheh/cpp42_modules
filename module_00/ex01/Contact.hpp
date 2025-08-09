
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <limits>
#define MAX_LIMIT std::numeric_limits<std::streamsize>::max()


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

#endif
