#include "so_long.h"

char *ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i--;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char	buff[1];
	char	str[100];
	char	*line;
	int		i;

	i = 0;
	str[0] = '\0';
	while (read(fd, buff, 1) > 0)
	{
		str[i] = buff[0];
		str[i + 1] = '\0';
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[0] == '\0')
		return (NULL);
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (str[++i])
		line[i] = str[i];
	line[i] = '\0';
	return (line);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		result[j++] = s2[i++];
	}
	result[j] = '\0';
	return (result);
}

void ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}