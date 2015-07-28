int	ft_test_foreach(char *str, int length, int(*f)(char))
{
	int res;
	int	i;

	res = 1;
	i = 0;
	while (res && i < length)
	{
		if (!f(str[i]))
			res = 0;
		i++;
	}
	return (res);
}
