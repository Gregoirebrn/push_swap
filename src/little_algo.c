/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:57:47 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/05 20:24:46 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	biggest_nbr(t_pile **a_pile)
{
	int		big;
	t_pile	*new;

	new = (*a_pile);
	big = new->content;
	while (new->next != NULL)
	{
		if (big < new->content)
			big = new->content;
		new = new->next;
	}
	if (big < new->content)
		big = new->content;
	return (big);
}

void	sort_three(t_pile **a_pile)
{
	int	big;

	big = biggest_nbr(a_pile);
	if (big == (*a_pile)->content)
		do_rotate(a_pile, NULL, 'a');
	else if (big == (*a_pile)->next->content)
		do_rev_rot(a_pile, NULL, 'a');
	if ((*a_pile)->content > (*a_pile)->next->content)
		do_swap(a_pile, NULL, 'a');
}
