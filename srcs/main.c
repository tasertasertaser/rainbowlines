/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 21:04:48 by cschulle          #+#    #+#             */
/*   Updated: 2019/09/01 16:28:45 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rainbows.h"

int		main(void)
{
	t_str	mr_struct;
	mr_struct.mlx = mlx_init();
	mr_struct.wn = mlx_new_window(mr_struct.mlx, WND_W, WND_H, "rainbowlines");
	mr_struct.img = img_factory(mr_struct.mlx);
	mr_struct.color = 0;
	mlx_hook(mr_struct.wn, 2, (1L << 0), keythings, &mr_struct);
	mlx_hook(mr_struct.wn, 6, (1L << 6), mousethings, &mr_struct);
	mlx_loop(mr_struct.mlx);
	return(0);
}


