#include "so_long.h"

int	strcount(char **spt, char elm)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	j = 0 ;
	while (spt[i])
	{
		j = 0;
		while (spt[i][j])
		{
			if (spt[i][j] == elm)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
int count_row(char **spt, t_data w)
{
	w.row = 0;
	while (spt[w.row])
	{
		w.col = 0;
		while (spt[w.row][w.col])
			w.col++;
		w.row++;
	}
	return (w.row);
}

int esc(int esc, t_data *w)
{
	if (esc == 53)
	{
		free(w->spt);
		exit (0);
	}
	return (0);
}

int close_win(t_data *w)
{
	free(w->spt);
	exit(0);
}
