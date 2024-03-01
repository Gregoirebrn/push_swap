/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:53:18 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/01 14:06:31 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_push(t_pile **a, t_pile **b, char c)
{
	if (c == 'b')
		ft_push(a, b);
	else
	{
		ft_push(b, b);
		ft_printf()
	}
}