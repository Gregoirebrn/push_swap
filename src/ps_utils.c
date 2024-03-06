/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:58:30 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/06 20:25:14 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sort(t_pile *a)
{
	t_pile	*parse;
	int		prev;

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

int	tab_to_pile(t_pile **a_pile, char **tab)
{
	size_t	x;
	long	nbr;
	t_pile	*new;

	x = 0;
	if (ft_strncmp(tab[x], "./push_swap", 10) == 0)
		x = 1;
	while (tab && tab[x])
	{
		nbr = ft_atoi(tab[x]);
		if (INT_MIN > nbr || INT_MAX < nbr)
			return (free_bird(a_pile, NULL), *a_pile = NULL, 1);
		new = ft_lstnew((int)nbr);
		if (!new)
			return ft_printf("Error\nCrash of Malloc.\n");
		ft_lstadd_back(a_pile, new);
		x++;
	}
	return (0);
}
