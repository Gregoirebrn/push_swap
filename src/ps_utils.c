/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:58:30 by grebrune          #+#    #+#             */
/*   Updated: 2024/02/12 22:23:46 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	tab_len(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

t_pile	*tab_to_pile(char **tab)
{
	size_t	x;
	size_t	i;
	t_pile	*pile;

	x = tab_len(tab);
	while (tab[x])
	{
		if (-2147483648 > ft_atoi(tab[x]) || 2147483647 < ft_atoi(tab[x]))
		{
			pile = NULL;
			return (ft_putstr_fd("Error\nAn argument is not an int.", 1), pile);
		}
		pile = ft_lstnew(tab[x]);
		pile = pile->next;
		x++;
	}
	return (pile);
}