/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:53:18 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/01 14:55:25 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_swap(t_pile **a, t_pile **b, char c)
{
	if (c == 's')
	{
		ft_swap(b);
		ft_swap(a);
		ft_printf("ss\n");
	}
	else if (c == 'b')
	{
		ft_swap(b);
		ft_printf("sb\n");
	}
	else
	{
		ft_swap(a);
		ft_printf("sb\n");
	}
}

void	do_push(t_pile **a, t_pile **b, char c)
{
	if (c == 'b')
	{
		ft_push(a, b);
		ft_printf("pb\n");
	}
	else
	{
		ft_push(b, a);
		ft_printf("pa\n");
	}
}

void	do_rotate(t_pile **a, t_pile **b, char c)
{
	if (c == 'r')
	{
		ft_rotate(b);
		ft_rotate(a);
		ft_printf("rr\n");
	}
	else if (c == 'b')
	{
		ft_rotate(b);
		ft_printf("rb\n");
	}
	else
	{
		ft_rotate(a);
		ft_printf("ra\n");
	}
}

void	do_rev_rot(t_pile **a, t_pile **b, char c)
{
	if (c == 'r')
	{
		ft_rev_rot(b);
		ft_rev_rot(a);
		ft_printf("rrr\n");
	}
	else if (c == 'b')
	{
		ft_rev_rot(b);
		ft_printf("rrb\n");
	}
	else
	{
		ft_rev_rot(a);
		ft_printf("rra\n");
	}
}

