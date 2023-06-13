#include <iostream>

class Contact
{
	char *_info;
};

class PhoneBook
{
public:
	PhoneBook()
	{
		for (int i = 0; i < 8; i++)
			_contacts[i] = 0;
	}
	void Add() { ; }

private:
	Contact _contacts[8];
	int _contactCount;
};

int main(int argc, char *argv[])
{

	return 0;
}
