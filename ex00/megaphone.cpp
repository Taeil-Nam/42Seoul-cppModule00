#include <iostream>

int main(int argc, char *argv[])
{
	size_t i = 1;
	size_t j = 0;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ('a' <= argv[i][j] && argv[i][j] <= 'z')
				argv[i][j] -= 32;
			j++;
		}
		std::cout << argv[i];
		i++;
	}
	std::cout << std::endl;

	return 0;
}
