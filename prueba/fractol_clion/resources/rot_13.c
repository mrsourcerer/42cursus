#include <unistd.h>

int	ft_rot13(char c)
{
	if (c  >= 'a' && c <= 'z')
	{
		if (c + 13 > 'z')
			return (c - 13);
		else
			return (c + 13);
	}
	if (c  >= 'A' && c <= 'Z')
	{
		if (c + 13 > 'Z')
			return (c - 13);
		else
			return (c + 13);
	}

	return (c);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	c;

	if (argc != 2)
		return (write(0, &"\n", 1), 0);
	i = 0;
	while (argv[1][i])
	{
		c = ft_rot13(argv[1][i]);
		write(0, &c, 1);
		i++;
	}
	write(0, &"\n", 1);
	return (0);
}

