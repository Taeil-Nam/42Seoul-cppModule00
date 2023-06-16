#pragma once
#include "Contact.h"

class PhoneBook
{
public:
	PhoneBook();
	void Add();
	void Search();
	int Exit();
private:
	bool IsEmptyContact(Contact* contact);
	void PrintContactsList(size_t i);
	void PrintContactInfo(size_t i);
	void DeleteEof();

private:
	Contact _contacts[8];
	size_t _contactIndex;
	Contact* _contact;
	bool _isFull;
};
