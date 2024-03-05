/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:35:14 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/05 15:54:11 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	stack_len(t_pile **a_pile)
{
	size_t	len;
	t_pile	*tmp;

	tmp = (*a_pile);
	while (tmp->next != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	sort_algo(t_pile **a_pile, t_pile **b_pile)
{
	size_t	i;
	size_t	len;
	int		bite;
	t_pile	*parse;

	parse = (*a_pile);
	len = stack_len(a_pile);
	i = 0;
	bite = 0;
	while (i < len)
	{
		if (*((int *)parse->content) >> bite & 1 == 0)
			do_push(a_pile, b_pile, 'b');
		else
			do_rotate(a_pile, b_pile, 'a');
		i++;
		bite++;
		if (i == len && (!check_sort(*a_pile)))
			i = 0;
	}
}

//void	sort_algo(t_pile **a, t_pile **b)
//{
//	int		index;
//	size_t	rank;
//	t_pile	*parkour;
//
//	rank = 0;
//	index = INT_MIN;
//	while (index < INT_MAX)
//	{
//		parkour = (*a);
//		while (parkour->next != NULL)
//		{
//			if (((int)parkour->content) == index)
//				parkour->rank = rank;
//		}
//		index++;
//		rank++;
//	}
//}
