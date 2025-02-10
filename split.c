#include "so_long.h"

static int	count_word(char const *str, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*str)
	{
		if (*str != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (*str == c)
			word = 0;
		str++;
	}
	return (count);
}

static char	*copy_the_word(char const *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_arr(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *str, char c)
{
	char	**arr;
	int		i;

	if (!str)
		return (NULL);
	arr = malloc((count_word(str, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			arr[i] = copy_the_word(str, c);
			if (!arr[i])
				return (free_arr(arr, i), NULL);
			i++;
		}
		while (*str && *str != c)
			str++;
	}
	arr[i] = NULL;
	return (arr);
}