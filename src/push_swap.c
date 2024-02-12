/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:29:47 by grebrune          #+#    #+#             */
/*   Updated: 2024/02/12 21:50:17 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_pile	a_pile;
	char	**tab;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		t_pile = tab_to_pile(tab);
	}
	return (0);
}