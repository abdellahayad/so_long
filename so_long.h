#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <libc.h>

# define size_pxl 32


typedef struct s_data
{
	int		fd;
	char	*line;
	char	*lines;
	char	**spt;
	char	*str;
	void	*mlx;
	void	*window;
	void	*imag;
	int		row;
	int		col;
	int 	length;
	int		width;
	int		hei;
	int		wid;
	int		num;
	int		count;
}	t_data;

int		check_map(char *map, t_data *w);
char	*ft_strrchr(const char *str, int c);
char	*get_next_line(int fd);
char	**ft_split(char const *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void 	ft_putstr(char *str);
int		ft_strlen(const char *str);
int		strcount(char **spt, char elm);
int		count_row(char **spt, t_data w);
void	create_game_features(t_data *w);
char	*int_to_str(int num);
int		esc(int esc, t_data *w);
int		close_win(t_data *w);
int		pos_in_colon(char **map);
int		pos_in_row(char **map);
int 	count_c(char **map);
int		move_player(int key, t_data *w);
int		free_and_exit(t_data *w);


#endif