/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:51:45 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/24 22:04:12 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	line(double x1, double y1, double x2, double y2)
{
	double	x;
	double	y;
	double	x_inc;
	double	y_inc;
	double	steps;

	x = x2 - x1;
	y = y2 - y1;
	if (fabs(x) > fabs(y))
		steps = fabs(x);
	else
		steps = fabs(y);
	x_inc = x / steps;
	y_inc = y / steps;
	while (steps-- >= 0)
	{
		y1 += y_inc;
		x1 += x_inc;
	}
}
