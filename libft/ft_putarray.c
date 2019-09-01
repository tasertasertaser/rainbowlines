/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:08:27 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/24 14:15:58 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarray(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		ft_putendl(array[i]);
		i++;
	}
	ft_putchar('\n');
}