/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:35:14 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/04 17:35:14 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_algo(t_pile **a, t_pile **b)
{
	int		index;
	size_t	rank;
	t_pile	*parkour;

	rank = 0;
	index = INT_MIN;
	while (index < INT_MAX)
	{
		parkour = (*a);
		while (parkour->next != NULL)
		{
			if (((int)parkour->content) == index)
				parkour->rank = rank;
		}
		index++;
		rank++;
	}
}
