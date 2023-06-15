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
	DeleteEof();
	_contact->SetLastName();
	DeleteEof();
	_contact->SetNickName();
	DeleteEof();
	_contact->SetPhoneNumber();
	DeleteEof();
	_contact->SetDarkestSecret();
	DeleteEof();

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
	size_t contactsSize;
	std::string selectedIndexString;
	size_t selectedIndex;
	std::stringstream ss;

	if (_isFull == false && _contactIndex == 0)
	{
		std::cout << "There is no contact. You should add contact first." << std::endl;
		return;
	}

	if (_isFull)
		contactsSize =	8;
	else
		contactsSize = _contactIndex;

	// 1. Print contacts info
	std::cout << std::setw(10) << "INDEX" << " | ";
	std::cout << std::setw(10) << "FIRST NAME" << " | ";
	std::cout << std::setw(10) << "LAST NAME" << " | ";
	std::cout << std::setw(10) << "NICKNAME" << std::endl;
	for (size_t i = 0; i < contactsSize; i++)
		PrintContactsList(i);
	
	// 2. Select index from user
	std::cout << "Select index : ";
	std::getline(std::cin, selectedIndexString);
	DeleteEof();
	if (selectedIndexString[0] < '0' || selectedIndexString[0] > '9')
	{
		std::cout << "Invalid index selected" << std::endl;
		return;
	}
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

	// 1. Print index
	std::cout << std::setw(10) << i << " | ";

	// 2. Print first name
	str = contact.GetFirstName();
	if (str.size() >= 10)
	{
		str[9] = '.';
		str.resize(10);
	}
	std::cout << std::setw(10) << str << " | ";

	// 3. Print last name
	str = contact.GetLastName();
	if (str.size() >= 10)
	{
		str[9] = '.';
		str.resize(10);
	}
	std::cout << std::setw(10) << str << " | ";

	// 4. Print nickname
	str = contact.GetNickName();
	if (str.size() >= 10)
	{
		str[9] = '.';
		str.resize(10);
	}
	std::cout << std::setw(10) << str << std::endl;
}

void PhoneBook::PrintContactInfo(size_t selectedIndex)
{
	std::cout << "First name : " << _contacts[selectedIndex].GetFirstName() << std::endl;
	std::cout << "Last name : " << _contacts[selectedIndex].GetLastName() << std::endl;
	std::cout << "Nickname : " << _contacts[selectedIndex].GetNickName() << std::endl;
	std::cout << "Phone Number : " << _contacts[selectedIndex].GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << _contacts[selectedIndex].GetDarkestSecret() << std::endl;
}

int PhoneBook::Exit()
{
	std::cout << "EXIT" << std::endl;
	return 0;
}

void PhoneBook::DeleteEof()
{
	if (std::cin.eof())
	{
		std::clearerr(stdin);
		std::cin.clear();
		std::cout << std::endl;
	}
}
