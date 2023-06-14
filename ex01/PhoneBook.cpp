#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "PhoneBook.h"

PhoneBook::PhoneBook() : _contactIndex(0), _contact(NULL), _isFull(false) {}

void PhoneBook::Add()
{
	Contact contactBackup;

	_contact = &(_contacts[_contactIndex]);
	contactBackup = *(_contact);

	_contact->SetFirstName();
	_contact->SetLastName();
	_contact->SetNickName();
	_contact->SetPhoneNumber();
	_contact->SetDarkestSecret();

	if (IsEmptyContact(_contact) == true)
	{
		*(_contact) = contactBackup;
		std::cout << "Not Added: There is empty contents in contact!" << std::endl;
		return;
	}
	else
	{
		_contactIndex++;
		if (_contactIndex >= 8)
		{
			_isFull = true;
			_contactIndex = 0;
		}
	}
}

bool PhoneBook::IsEmptyContact(Contact* contact)
{
	if (contact->GetFirstName() == "" || contact->GetLastName() == ""
		|| contact->GetNickName() == "" || contact->GetPhoneNumber() == ""
		|| contact->GetDarkestSecret() == "")
		return true;
	return false;
}

void PhoneBook::Search()
{
	size_t end_i;
	std::string selectedIndexString;
	size_t		selectedIndex;
	std::stringstream ss;

	if (_isFull == false && _contactIndex == 0)
	{
		std::cout << "There is no contact. You should add contact first." << std::endl;
		return;
	}

	if (_isFull)
		end_i =	8;
	else
		end_i = _contactIndex;

	for (size_t i = 0; i < end_i; i++)
		PrintContactsList(i);
	
	std::cout << "Select index : ";
	std::getline(std::cin, selectedIndexString);
	ss << selectedIndexString;
	ss >> selectedIndex;
	if (selectedIndex > 7 || (_isFull == false && selectedIndex >= _contactIndex))
	{
		std::cout << "Invalid index selected" << std::endl;
		return;
	}
	else
		PrintContactInfo(selectedIndex);
}

void PhoneBook::PrintContactsList(size_t i)
{
	Contact contact;
	std::string str;

	contact = _contacts[i];

	// 1. index
	std::cout << std::setfill(' ') << std::setw(10) << i << " | ";

	// 2. first name
	str = contact.GetFirstName();
	if (str.size() >= 10)
	{
		str[9] = '.';
		str.resize(10);
	}
	std::cout << std::setfill(' ') << std::setw(10) << str << " | ";

	// 3. last name
	str = contact.GetLastName();
	if (str.size() >= 10)
	{
		str[9] = '.';
		str.resize(10);
	}
	std::cout << std::setfill(' ') << std::setw(10) << str << " | ";

	// 4. nickname
	str = contact.GetNickName();
	if (str.size() >= 10)
	{
		str[9] = '.';
		str.resize(10);
	}
	std::cout << std::setfill(' ') << std::setw(10) << str << std::endl;
}

void PhoneBook::PrintContactInfo(size_t i)
{
	std::cout << "First name : " << _contacts[i].GetFirstName() << std::endl;
	std::cout << "Last name : " << _contacts[i].GetLastName() << std::endl;
	std::cout << "Nickname : " << _contacts[i].GetNickName() << std::endl;
	std::cout << "Phone Number : " << _contacts[i].GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << _contacts[i].GetDarkestSecret() << std::endl;
}

int PhoneBook::Exit()
{
	std::cout << "Exit" << std::endl;
	return 0;
}
