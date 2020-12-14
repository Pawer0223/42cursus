double		ft_pow(double base, double exponent)
{
	double	result;
	int		i;

	if ((int)exponent == 0)
		return (1);
	result = 1;
	i = 0;
	if (exponent < 0)
	{
		i = exponent;
		while (i++ < 0)
			result /= base;
	}
	else
	{
		while (i++ < exponent)
			result *= base;
	}
	return (result);
}