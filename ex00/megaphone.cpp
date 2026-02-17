#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	if (1 < ac)
	{
		for (int i = 1; av[i]; i++)
		{
			for (int j = 0; av[i][j]; j++)
				std::cout << (unsigned char)toupper(av[i][j]);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";

	return (0);
}
