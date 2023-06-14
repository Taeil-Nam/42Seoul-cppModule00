#pragma once
#include <string>

class Contact
{
public:
	void SetFirstName();
	void SetLastName();
	void SetNickName();
	void SetPhoneNumber();
	void SetDarkestSecret();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickName();
	std::string GetPhoneNumber();
	std::string GetDarkestSecret();
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;
};
