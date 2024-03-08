/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:57:47 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/08 21:16:06 by grebrune         ###   ########.fr       */
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

int	little_nbr(t_pile **a_pile)
{
	int		lit;
	t_pile	*new;

	new = (*a_pile);
	lit = new->content;
	while (new->next != NULL)
	{
		if (lit > new->content)
			lit = new->content;
		new = new->next;
	}
	if (lit > new->content)
		lit = new->content;
	return (lit);
}

void	sort_last(t_pile **a_pile)
{
	t_pile	*last;

	last = ft_lstlast(*a_pile);
	if (last->rank == 1)
	{
		do_rev_rot(a_pile, NULL, 'a');
		return ;
	}
}

void	sort_five(t_pile **a_pile, t_pile **b_pile)
{
	size_t	i;

	i = 1;
	init_five(a_pile);
	sort_rank(a_pile);
	sort_last(a_pile);
	while (ft_lstsize(*a_pile) != 3)
	{
		if ((*a_pile)->rank == i)
		{
			do_push(a_pile, b_pile, 'b');
			i++;
		}
		else
			do_rotate(a_pile, b_pile, 'a');
	}
	if ((*b_pile)->rank != 2)
		do_rotate(a_pile, b_pile, 'b');
	sort_three(a_pile);
	while (*b_pile != NULL)
		do_push(a_pile, b_pile, 'a');
}
