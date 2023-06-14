#include <iostream>
#include "Contact.h"

void Contact::SetFirstName()
{
	std::cout << "Enter the First name : ";
	std::getline(std::cin, _firstName);
}
void Contact::SetLastName()
{
	std::cout << "Enter the Last name : ";
	std::getline(std::cin, _lastName);
}

void Contact::SetNickName()
{
	std::cout << "Enter the Nickname : ";
	std::getline(std::cin, _nickName);
}

void Contact::SetPhoneNumber()
{
	std::cout << "Enter the Phone number : ";
	std::getline(std::cin, _phoneNumber);
}

void Contact::SetDarkestSecret()
{
	std::cout << "Enter the Darkest secret : ";
	std::getline(std::cin, _darkestSecret);
}

std::string Contact::GetFirstName()
{
	return _firstName;
}
std::string Contact::GetLastName()
{
	return _lastName;
}

std::string Contact::GetNickName()
{
	return _nickName;
}

std::string Contact::GetPhoneNumber()
{
	return _phoneNumber;
}

std::string Contact::GetDarkestSecret()
{
	return _darkestSecret;
}
