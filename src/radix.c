/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:35:14 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/05 21:23:06 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	stack_len(t_pile **a_pile)
{
	size_t	len;
	t_pile	*tmp;

	tmp = (*a_pile);
	len = 0;
	if (tmp)
		len++;
	while (tmp->next != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	sort_pb(t_pile **a_pile, t_pile **b_pile, t_sort *sort)
{
	while (sort->len_b > 0)
	{
		do_push(a_pile, b_pile, 'a');
		sort->len_b--;
	}
}

void	sort_rank(t_pile **a_pile)
{
	int		big;
	size_t	rank;
	size_t	len;
	t_pile	*new;

	new = (*a_pile);
	len = ft_lstsize(new);
	rank = 1;
	while (rank < len + 1)
	{
		new = (*a_pile);
		big = INT_MIN;
		while (new->next != NULL)
		{
			if ((big <= new->content) && (new->rank == 0))
				new->rank = rank;
			new = new->next;
			rank++;
		}
	}
	if (big < new->content)
		big = new->content;
}

void	sort_init_struct(t_sort *sort, t_pile **a_pile)
{
	t_pile	*init;

	sort->len = stack_len(a_pile);
	sort->bit = 0;
	sort->len_b = 0;
	init = (*a_pile);
	while (init->next != NULL)
	{
		init->rank = 0;
		init = init->next;
	}
	init->rank = 0;
	sort_rank(a_pile);
}

void	sort_algo(t_pile **a_pile, t_pile **b_pile)
{
	t_sort	sort;

	sort_init_struct(&sort, a_pile);
	while (!check_sort(*a_pile))
	{
		sort.i = 0;
		while (sort.i < sort.len)
		{
			sort.parse = (*a_pile);
			if (sort.parse->rank >> sort.bit & 1)
				do_rotate(a_pile, b_pile, 'a');
			else
			{
				do_push(a_pile, b_pile, 'b');
				sort.len_b++;
			}
			sort.i++;
		}
		sort_pb(a_pile, b_pile, &sort);
		print_list(a_pile);
		printf("=========\n");
		print_list(b_pile);
		sort.bit++;
	}
}
