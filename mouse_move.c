/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:41:36 by lvania            #+#    #+#             */
/*   Updated: 2019/11/24 14:42:09 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, void *param)
{
	t_common	*ptr;

	ptr = (t_common *)param;
	if ((0 < x && x < WW) && (0 < y && y < WH))
	{
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		ptr->jul_fr.cre = ((double)x - WW / 2) / (WW / 2);
		ptr->jul_fr.cim = ((double)y - WH / 2) / (WH / 2);
		julia(ptr, &(ptr->jul_fr));
	}
	return (0);
}
