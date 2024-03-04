/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:58:30 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/04 21:34:03 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_sort(t_pile *a)
{
	t_pile	*parse;
	void	*prev;

	parse = a;
	while (parse->next != NULL)
	{
		prev = parse->content;
		parse = parse->next;
		if (prev > parse->content)
			return (0);
	}
	return (1);
}

size_t	tab_len(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	tab_to_pile(t_pile **a_pile, char **tab)
{
	size_t	x;
	long	nbr;
	t_pile	*new;

	x = 0;
	while (tab && tab[x])
	{
		nbr = ft_atoi(tab[x]);
		if (INT_MIN > nbr || INT_MAX < nbr)
		{
			*a_pile = NULL;
			return ;
		}
		new = ft_lstnew((void *)nbr);
		if (!new)
		{
			ft_printf("Error\nCrash of Malloc.\n");
			return ;
		}
		ft_lstadd_back(a_pile, new);
		x++;
	}
}