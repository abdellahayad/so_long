#include "so_long.h"

static int check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_element(char **spt)
{
	int	i;
	int	j;

	i = 0;
	while (spt[i])
	{
		j = 0;
		while (spt[i][j])
		{
			if (spt[i][j] != 'P' && spt[i][j] != 'C' && spt[i][j] != '0'
				&& spt[i][j] != '1' && spt[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
	}
	if (strcount(spt, 'P') == 1 && strcount(spt, 'E') == 1
		&& strcount(spt, 'C') != 0)
		return (0);
	return (1);
}
static int map_is_valid(char **spt)
{
	int		i;
	int 	len;
	if (check_line(spt[0]) == 1)
		return (1);
	i = 0;
	while (spt[i + 1])
	{
		len = ft_strlen(spt[i]);
		if (len != ft_strlen(spt[i + 1]))
			return (1);
		if (spt[i][0] != '1' || spt[i][len - 1] != '1')
			return (1);
		i++;
	}
	if (check_line(spt[i]) == 1 || check_element(spt) == 1)
		return (1);
	return (0);
}
static int check_extention(char *m1, char *m2)
{
	int	i;

	m1 = ft_strrchr(m1, '.');
	if (m1 == NULL)
		return (0);
	i = 0;
	while (m2[i])
	{
		if (m1[i] != m2[i])
			return (0);
		i++;
	}
	return (m1[i] == '\0');
}
int check_map(char *map, t_data *w)
{
	char *temp;
	w->fd = open(map, O_RDONLY);
	if (check_extention(map, ".ber") == 0 || w->fd == -1)
		return (ft_putstr("🔻Error : incorrect map"), 1);
	while (1)
	{
		w->line = get_next_line(w->fd);
		if (!w->line)
			break ;
		if (!w->lines)
			w->lines = ft_strjoin("", w->line);
		else
		{
			temp = ft_strjoin(w->lines, w->line);
			free (w->lines);
			w->lines = temp;
		}
		free((w->line));
	}
	if (!w->lines)
		return (free(w->lines), ft_putstr("🔻Error : invalid map\n"), 1);
	w->spt = ft_split(w->lines, '\n');
	if (map_is_valid(w->spt) == 1)
		return (free(w->spt), ft_putstr("🔻Error : invalid map\n"), 1);
	return (0);
}
