/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:43:26 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/22 17:02:38 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETS_H
# define SETS_H

# include <math.h>
# include <stdlib.h>
# include <mlx.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
}				t_data;

typedef struct s_fractol {
	long double			nbx;
	long double			nby;
	long double			mx;
	long double			my;
	long double			tmx;
	long double			tmy;
	long double			x;
	long double			y;
	long double			tmp;
	long double			zoom;
	int					rgb;
}				t_fractol;

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_program {
	void				*mlx;
	long double			cx;
	long double			cy;
	t_data				img;
	t_window			window;
	t_fractol			fractol;
}				t_program;

# ifndef MAXITERATION
#  define MAXITERATION 100
# endif

int			jpixelcalculator(long double x, long double y, t_program *m);
void		jspawner(t_data img, t_fractol *mset, t_program *m);
void		julia_set(long double cx, long double cy);
int			ft_jchangecolor(t_program *param);
int			ft_jinput123(t_program *param);
int			ft_jinput124(t_program *param);
int			ft_jinput125(t_program *param);
int			ft_jinput126(t_program *param);
int			ft_jinput51(int x, int y, t_program *param);
int			ft_jinput(int key, int x, int y, t_program *param);
int			ft_jinputk(int key, t_program *param);
int			ft_jinput42(int x, int y, t_program *param);
int			ft_input(int key, int x, int y, t_program *param);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			rgb(int rgb);
void		mandelbrot_set(void);
void		julia_set(long double zx, long double zy);
t_window	new_window(void *mlx, int widht, int height, char *name);
int			ft_update(t_program *param);
void		mspawner(t_data img, t_fractol *mset);
int			ft_input51(int x, int y, t_program *param);
int			ft_input42(int x, int y, t_program *param);
int			ft_inputk(int key, t_program *param);
int			ft_input123(t_program *param);
int			ft_input124(t_program *param);
int			ft_input125(t_program *param);
int			ft_input126(t_program *param);
int			ft_changecolor(t_program *param);
int			ft_close(t_program *vars);
void		burningship_set(void);
void		bspawner(t_data img, t_fractol *mset);
int			bpixelcalculator(long double x, long double y, long double zoom,
				t_fractol *m);
int			ft_bchangecolor(t_program *param);
int			ft_binput123(t_program *param);
int			ft_binput124(t_program *param);
int			ft_binput125(t_program *param);
int			ft_binput126(t_program *param);
int			ft_binput42(int x, int y, t_program *param);
int			ft_binput51(int x, int y, t_program *param);
int			ft_binputk(int key, t_program *param);
int			ft_binput(int key, int x, int y, t_program *param);

#endif
