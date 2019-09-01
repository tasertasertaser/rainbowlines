/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 21:54:19 by cschulle          #+#    #+#             */
/*   Updated: 2019/09/01 16:22:06 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbows.h"

void	clear_image(t_im *image)
{
	ft_bzero(image->pixels, WND_W * WND_H * sizeof(image->pixels[0]));
}

void	drawpixel(t_im *im, int x, int y, int color)
{
	int pix;

	pix = (y * WND_W) + x;
	if (x >= 0 && x < WND_W && y >= 0 && y < WND_H)
		im->pixels[pix] = color;
}

t_im	*img_factory(void *mlx)
{
	int		bwoop;
	t_im	*image;

	bwoop = 0;
	if (!(image = malloc(sizeof(t_im *))))
		error("not enough memory.\n");
	image->imptr = mlx_new_image(mlx, WND_W, WND_H);
	image->pixels = (int *)mlx_get_data_addr(image->imptr,
		&bwoop, &bwoop, &bwoop);
	return (image);
}
