#include "so_long.h"

static void write_digits(char *str, unsigned int num, long int i)
{
	while (num > 0)
	{
		str[i--] = '0' + (num % 10);
		num /= 10;
	}
}

static long int count_digit(long int num)
{
	long int	count;

	count = 0;
	if (num <= 0)
		count = 1;
	while (num != 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}

char	*int_to_str(int num)
{
	char			*str;
	long int		length;
	unsigned int	abs_num;
	long int		num_long;	

	num_long = num;
	length = count_digit(num_long);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str[length--] = '\0';
	if (num_long == 0)
		str[0] = '0';
	if (num_long < 0)
	{
		abs_num = -num_long;
		str[0] = '-';
	}
	else
		abs_num = num_long;
	write_digits(str, abs_num, length);
	return (str);
}
