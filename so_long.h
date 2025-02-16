/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayad <aayad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:32:38 by aayad             #+#    #+#             */
/*   Updated: 2025/02/15 21:15:33 by aayad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <libc.h>

# define px 32


typedef struct s_data
{
	int		fd;
	char	*line;
	char	*lines;
	char	**spt;
	char	*str;
	void	*mlx;
	void	*win;
	void	*img;
	int		r;
	int		c;
	int 	length;
	int		width;
	int		h;
	int		w;
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
void	ft_free(t_data *w);
char	*ft_strdup(const char *s1);
int		flood_fill_check(t_data *w);


#endif