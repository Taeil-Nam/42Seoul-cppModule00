#include <iostream>
#include <string>
#include <cstdio>
#include "PhoneBook.h"
#include "Contact.h"

int main()
{
	PhoneBook phoneBook;
	std::string input;

	while(true)
	{
		std::cout << "Enter the command (ADD, SEARCH, EXIT) : ";
		std::getline(std::cin, input);

		if (std::cin.eof())
		{
			std::clearerr(stdin);
			std::cin.clear();
			std::cout << std::endl;
		}
		else if (input == "ADD")
			phoneBook.Add();
		else if (input == "SEARCH")
			phoneBook.Search();
		else if (input == "EXIT")
			return phoneBook.Exit();
		else
			std::cout << "Not supported command: " << input << std::endl;

		std::cout << std::endl;
	}
	return 0;
}
