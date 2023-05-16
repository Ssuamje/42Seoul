/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:28:45 by sanan             #+#    #+#             */
/*   Updated: 2022/12/26 14:31:35 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef W_RANGE
#  define W_RANGE 1920
# endif
# ifndef H_RANGE
#  define H_RANGE 1080
# endif
# ifndef W_SIZE
#  define W_SIZE 60
# endif
# ifndef H_SIZE
#  define H_SIZE 60
# endif
# include "./MLX/minilibx_opengl/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_move{
	int	dx[4];
	int	dy[4];
}	t_move;

typedef struct s_loc{
	int	x;
	int	y;
}	t_loc;

typedef struct s_info{
	char	**map;
	int		col_map;
	int		row_map;
	t_loc	loc_player;
	t_move	move;
	int		**visit_list;
	int		point_collect;
	int		point_start;
	int		point_escape;
	int		dfs_collect;
	int		dfs_escape;
	int		count_moves;
}	t_info;

typedef struct s_ptrs{
	void	*mlx;
	void	*window;
	void	*img_player;
	void	*img_empty;
	void	*img_collect;
	void	*img_wall;
	void	*img_escape;
	t_info	*info;
}	t_ptrs;

enum e_key{
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2
};

enum e_error_bool{
	EXIT_ERROR = -1,
	FALSE,
	TRUE,
	ERROR_SIZE,
	ERROR_COMPONENT,
	ERROR_WALL,
	ERROR_RECTANGULAR,
	ERROR_INIT,
	ERROR_POINT,
	ERROR_INVALID_MAP,
	ERROR_MAP
};

void	catch_collect_escape(int row, int col, t_info *info);
void	catch_component(int row, int col, t_info *info);
int		check_extension(char *dir);
int		check_map_format(t_info *info);
int		check_map_path(t_info *info);
int		check_map_size(t_info *info);
int		check_map_wall(t_info *info, int row);
void	clear_info(t_info *info);
int		clear_and_exit(t_ptrs *ptrs, int flag);
void	clear_img(t_ptrs *ptrs);
void	dfs_catch_component(int row, int col, t_info *info);
void	dfs_path(int y, int x, t_info *info);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup(const char *src);
void	game_clear(t_ptrs *ptrs);
int		get_col(char *row);
int		get_key(int keycode, t_ptrs *ptrs);
int		get_row(char **map);
void	get_loc_player(t_info *info);
char	**get_map(char *dir);
int		init_info(t_info *info);
int		is_point_valid(t_info *info);
int		is_top_bottom(char *row, int len, t_info *info);
int		is_surrounded(char *row);
int		is_charset(char c, char *charset);
int		**make_visit_list(t_info *info);
void	set_move(t_move *move);
int		print_error(int error_code);
void	update_player_loc(t_ptrs *ptrs, int dx, int dy);
void	render_map(t_ptrs *ptrs);

#endif