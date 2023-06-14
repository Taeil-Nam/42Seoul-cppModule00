#include <iostream>

int main(int argc, char *argv[])
{
	std::string str;
	size_t i = 1;
	size_t j = 0;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	while (argv[i])
	{
		str = argv[i];
		j = 0;
		while (str[j])
		{
			str[j] = std::toupper(str[j]);
			j++;
		}
		std::cout << str;
		i++;
	}
	std::cout << std::endl;

	return 0;
}
