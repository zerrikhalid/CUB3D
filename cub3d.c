/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:11:30 by kzerri            #+#    #+#             */
/*   Updated: 2023/12/10 12:12:38 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
	t_mlx		mlx;
	t_player	player;

	set_up_window(&mlx, &player);
	keep_window_opened(&mlx, &player);
}
