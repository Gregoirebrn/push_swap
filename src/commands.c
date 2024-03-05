/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:37:11 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/05 19:02:18 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_pile **lst)
{
	t_pile	*new;

	if (ft_lstsize(*lst) < 2)
		return ;
	new = (*lst)->next;
	(*lst)->next = new->next;
	new->next = *lst;
	*lst = new;
}

void	ft_push(t_pile **a, t_pile **b)
{
	t_pile	*new;

	if (!*a)
		return ;
	new = *a;
	*a = new->next;
	new->next = *b;
	*b = new;
}

void	ft_rotate(t_pile **lst)
{
	t_pile	*new;
	t_pile	*last;
	t_pile	*size;

	size = *lst;
	if (ft_lstsize(size) == 1)
		return ;
	new = *lst;
	*lst = (*lst)->next;
	last = ft_lstlast(*lst);
	last->next = new;
	new->next = NULL;
}

void	ft_rev_rot(t_pile **lst)
{
	t_pile	*last;
	t_pile	*before;

	before = *lst;
	while (before->next->next != NULL)
		before = before->next;
	last = before->next;
	before->next = NULL;
	last->next = *lst;
	*lst = last;
}
