/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbows.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:47:13 by cschulle          #+#    #+#             */
/*   Updated: 2019/09/01 16:24:15 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
**	======== inclyoooods ========
*/

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

/*
**	======== stroooocts ========
*/

typedef struct		s_im
{
	void			*imptr;
	int				*pixels;
}					t_im;

typedef struct		s_str
{
	void			*wn;
	void			*mlx;
	t_im			*img;
	int				color;
	int				fractype;
}					t_str;

/*
**	======== display ========
*/

# define WND_W 1280
# define WND_H 720

/*
**	======== colorstuff ========
*/

# define R(a) (a) >> 16
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(a, b, c) ((a) << 16) + ((b) << 8) + (c)

# define PNK 0xFF57A4
# define ORN 0xF99C4F
# define YLW 0xFCD14F
# define GRN 0x97F53B
# define AQU 0x43FFB5
# define BLU 0x53ADFC
# define PRP 0x9F29FF
# define GRY 0x404040
# define BLK 0x000000
# define WHT 0xFFFFFF

/*
**	======== fn declarations ========
*/

/*
**	...user interface...
*/
int		keythings(int key, t_str *mr_struct);
int		mousethings(int x, int y, t_str *mr_struct);

/*
**	...images & pixel-putting...
*/
t_im	*img_factory(void *mlx);
void	drawpixel(t_im *im, int x, int y, int color);
void	clear_image(t_im *image);

/*
**	...error...
*/
void				error(char *description);
void				usage(void);

#endif
