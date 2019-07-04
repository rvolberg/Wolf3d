/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:23:29 by tlaberro          #+#    #+#             */
/*   Updated: 2019/03/22 14:02:48 by rvolberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "key.h"
# include "libft.h"

# define CUBE_SIZE 12
# define W_W 1280
# define W_H 800
//# define malloc(x) NULL//

# define KEYPRESS 2

typedef struct			s_pixel
{
	int					x;
	int					y;
	int					z;
}						t_pixel;

typedef struct			s_graphic
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*img;
	int					bpp;
	int					s_l;
	int					endian;
	int					height;
	int					width;
}						t_graphic;

typedef struct			s_raycasting
{
	double				vstepx;
	double				vstepy;
	double				camx;
	double				camy;
	double				rayx;
	double				rayy;
	double				move_speed;
	double				angle_rotate;
	double				length;
	double				fov;
	double				gridx;
	double				gridy;
	double				px;
	double				py;
	double				ratio;
	double				xdir;
	double				ydir;
	double				xstep;
	double				ystep;
}						t_raycast;

typedef struct			s_data
{
	t_graphic			*graph;
	t_raycast			*ray;
	t_pixel				**tab_int;
	t_graphic			*wall1;
	t_graphic			*wall2;
	t_graphic			*wall3;
	t_graphic			*wall4;
	t_graphic			*menu1;
	int					fd;
	char				*map_raw;
	char				**map;
	int					column;
	int					line;
	int					height;
	int					width;
	int					cube;
	int					xi;
	int					yi;
	int					text_height;
	int					text_width;
	char				*text_img;
	int					xdecale;
	int					ydecale;
	int					rayhit;
	int					rayhitside;
	double				sidedistx;
	double				sidedisty;
	int					color_1;
	int					color_2;
	int					color_3;
	int					color_4;
	int					color_5;
	int					color_ground;
	int					color_sky;
	int					menu;
}						t_data;

void					ft_reader(t_data *env, char *av);
void					ft_read_support(t_data *env, char *line);
void					ft_charcheck(char *line, int fd, t_data *env);
void					ft_placecheck(char *str, int fd, t_data *env);
void					ft_checkwall(char **map, t_data *env);
void					ft_cw_support(char **map, t_data *env, int len, int y);
void					ft_init_window(t_data *env);
t_graphic				*ft_init_graph(void);
t_raycast				*ft_init_ray(void);
int						ft_init_list(t_data *env);
void					ft_init_texture(t_data *env);
int						ft_open(char *str, t_data *env);
void					ft_free_tab_data(char **tab, int i);
void					ft_exit(int fd, t_data *env, char *str);
char					*ft_back_n(char *map, int fd, t_data *env);
void					img_pixel(t_data *env, int x, int y, int color);
int						ft_close(t_data *env);
void					ft_fill_list(t_data *env);
int						ft_window_output(t_data *env);
void					new_image(t_data *env);
int						ft_place_perso(t_data *env);
void					ft_draw_mini(t_data *env);
int						ft_map(t_data *env, int key, int j);
void					ft_print_square(t_data *env, int x, int y, int color);
void					ft_print_perso(t_data *env, int x, int y, int color);
int						ft_perso_move(int key, t_data *env);
void					ft_option(int key, t_data *env);
int						deal_key(int key, t_data *env);
void					raycasting(t_data *env);
void					ray_first_step_side(t_data *env);
void					ray_cal_dist(t_data *env);
void					ray_draw(t_data *env, int x);
unsigned int			get_color(t_data *env);
void					ft_draw_line(t_data *env, int x, int start, int end);
void					ft_move_up_down(t_data *env, int key);
void					ft_move_right_left(t_data *env, int key);
void					rotate_right(t_data *env);
void					rotate_left(t_data *env);
double					ft_hit_coord(t_data *env);
int						ft_wall(t_data *env, int d, int wall_height);
void					ft_which_face(t_data *env);
void					support_wall(t_data *env, int h, int w, char *img);
void					ft_supportray(t_data *env);
void					free_struct(t_data *env);

#endif
