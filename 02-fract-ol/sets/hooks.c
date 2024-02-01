/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:23:01 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/12/22 15:40:54 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sets.h"

int	ft_input(int key, int x, int y, t_program *param)
{
	if (key == 5 || key == 1)
		ft_input51(x, y, param);
	else if (key == 4 || key == 2)
		ft_input42(x, y, param);
	return (0);
}

int	ft_inputk(int key, t_program *param)
{
	if (key == 123)
		ft_input123(param);
	else if (key == 124)
		ft_input124(param);
	else if (key == 125)
		ft_input125(param);
	else if (key == 126)
		ft_input126(param);
	else if (key == 12)
		ft_changecolor(param);
	if (key == 53)
		ft_close(param);
	return (0);
}

int	ft_input51(int x, int y, t_program *param)
{
	param->fractol.tmx += x / param->fractol.zoom;
	param->fractol.tmy += y / param->fractol.zoom;
	param->fractol.zoom *= 2.;
	param->fractol.mx = param->fractol.tmx * param->fractol.zoom;
	param->fractol.my = param->fractol.tmy * param->fractol.zoom;
	mlx_clear_window(param->mlx, param->window.reference);
	mspawner(param->img, &param->fractol);
	mlx_put_image_to_window(param->mlx, param->window.reference,
		param->img.img, 0, 0);
	return (0);
}

int	ft_input42(int x, int y, t_program *param)
{
	if (param->fractol.zoom > 2)
	{
		param->fractol.tmx -= x / param->fractol.zoom;
		param->fractol.tmy -= y / param->fractol.zoom;
		param->fractol.zoom /= 2.;
		param->fractol.mx = param->fractol.tmx * param->fractol.zoom;
		param->fractol.my = param->fractol.tmy * param->fractol.zoom;
		mlx_clear_window(param->mlx, param->window.reference);
		mspawner(param->img, &param->fractol);
		mlx_put_image_to_window(param->mlx, param->window.reference,
			param->img.img, 0, 0);
	}
	else if (param->fractol.zoom == 2)
	{
		param->fractol.tmx = 0;
		param->fractol.tmy = 0;
		param->fractol.zoom = 1;
		param->fractol.mx = 0;
		param->fractol.my = 0;
		mlx_clear_window(param->mlx, param->window.reference);
		mspawner(param->img, &param->fractol);
		mlx_put_image_to_window(param->mlx, param->window.reference,
			param->img.img, 0, 0);
	}
	return (0);
}
