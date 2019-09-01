/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:18:30 by cschulle          #+#    #+#             */
/*   Updated: 2019/09/01 16:22:07 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Prints description of program error in red.
**	Exits the program.
*/

#include "../includes/rainbows.h"

void	error(char *description)
{
	ft_putstr(P_RD);
	ft_putendl(description);
	ft_putstr(P_X);
	exit(1);
}

