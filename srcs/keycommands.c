/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycommands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 17:05:27 by cschulle          #+#    #+#             */
/*   Updated: 2019/09/01 16:23:43 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbows.h"
#include "../includes/keys.h"

int		findcolor(t_str *mr_struct)
{
	int colors[7] = {PNK, ORN, YLW, GRN, AQU, BLU, PRP};
	if(mr_struct->color == 6)
		mr_struct->color = 0;
	else
		mr_struct->color++;
	return(colors[mr_struct->color]);
}

void	quitprog(t_str *mr_struct)
{
	mlx_destroy_image(mr_struct->mlx, mr_struct->img);
	mlx_destroy_window(mr_struct->mlx, mr_struct->wn);
	exit(0);
}

int		mousethings(int x, int y, t_str *mr_struct)
{
	drawpixel(mr_struct->img->imptr, x, y, findcolor(mr_struct));
	mlx_put_image_to_window(mr_struct->mlx, mr_struct->wn,
		mr_struct->img->imptr, 0, 0);
	return (0);
}

int		keythings(int key, t_str *mr_struct)
{
	if (key == ESC_KEY)
		quitprog(mr_struct);
	if (key == SPACE_KEY)
		clear_image(mr_struct->img);
	return (0);
}