#pragma once
#include "Contact.h"

class PhoneBook
{
public:
	PhoneBook();
	void Add();
	bool IsEmptyContact(Contact* contact);
	void Search();
	void PrintContactsList(size_t i);
	void PrintContactInfo(size_t i);
	int Exit();
private:
	void DeleteEof();
private:
	Contact _contacts[8];
	size_t _contactIndex;
	Contact* _contact;
	bool _isFull;
};
