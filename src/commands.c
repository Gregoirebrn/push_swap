/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:37:11 by grebrune          #+#    #+#             */
/*   Updated: 2024/02/12 22:54:47 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_pile *lst)
{
	t_pile	*last;
	t_pile	*minus;

	if (2 > ft_lstsize(lst))
		return ;
	minus = lst;
	last = lst;
	while (minus->next->next != NULL)
		minus = minus->next;
	ft_lstlast(last);
	lst->content = last->content;
	lst = lst->next;
	lst->content = minus->content;
}

void	ft_push(t_pile *a, t_pile *b)
{

}

void	ft_rotate(t_pile *lst)
{

}

void	ft_rev_rot(t_pile *lst)
{

}