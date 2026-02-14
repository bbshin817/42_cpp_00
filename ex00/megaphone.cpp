#include <iostream>

int	main(int ac, char **av)
{
	int 					i;
	std::string::size_type	li;
	std::string				str;

	i = 1;
	if (1 < ac)
	{
		while (i < ac)
		{
			str = av[i];
			li = 0;
			while (li < str.size())
			{
				if ('a' <= str[li] && str[li] <= 'z')
					std::cout << (char)(str[li] + ('A' - 'a'));
				else
					std::cout << str[li];
				li++;
			}
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << '\n';

	return (0);
}
