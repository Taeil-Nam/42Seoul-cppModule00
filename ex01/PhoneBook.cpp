#include <iostream>
#include <string>

class Contact
{
public:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _DarkestSecret;
};

class PhoneBook
{
public:
	PhoneBook()
	{
		_contactCount = 0;
	}
	void Add()
	{
		std::cout << "Enter the First name : ";
		std::cin >> _contacts[_contactCount]._firstName;
		std::cout << "Enter the Last name : ";
		std::cin >> _contacts[_contactCount]._lastName;
		std::cout << "Enter the Nick name : ";
		std::cin >> _contacts[_contactCount]._nickName;
		std::cout << "Enter the Phone number : ";
		std::cin >> _contacts[_contactCount]._phoneNumber;
		std::cout << "Enter the Darkest secret : ";
		std::cin >> _contacts[_contactCount]._DarkestSecret;
		_contactCount++;
		if (_contactCount >= 8)
			_contactCount = 0;
	}
	void Search()
	{
		
	}
private:
	int _contactCount;
	Contact _contacts[8];
};

int main(int argc, char *argv[])
{
	PhoneBook phoneBook;
	std::string input;

	while(true)
	{
		std::cout << "Enter the command (ADD, SEARCH, EXIT) : ";
		std::cin >> input;

		if (std::cin.eof())
			break;
		else if (input == "ADD")
		{
			phoneBook.Add();
		}
		else if (input == "SEARCH")
		{
			phoneBook.Search();
		}
		else if (input == "EXIT")
		{
			std::cout << "EXIT" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "Not support command: " << input << std::endl << std::endl;
		}
	}
	return 0;
}
