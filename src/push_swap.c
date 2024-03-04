/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:29:47 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/04 21:51:38 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_av(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	while (0 < i)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
}

void	free_bird(t_pile **a, char **av)
{
	t_pile	*tmp;

	tmp = (*a);
	while (*a)
	{
		tmp = tmp->next;
		free(*a);
		(*a) = tmp;
	}
	free_av(av);
}

void	print_list(t_pile **a)
{
	int		i;
	t_pile	*parkour;

	parkour = *a;
	i = 0;
	while (parkour->next != NULL)
	{
		ft_printf("%d = %d\n", i, parkour->content);
		parkour = parkour->next;
		i++;
	}
	ft_printf("%d = %d\n", i, parkour->content);
}

int	main(int ac, char **av)
{
	t_pile	*a_pile;
	t_pile	*b_pile;

	a_pile = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (ft_printf("Error\nMissing Args.\n"));
	if (ac == 2)
		av = ft_split(av[1], ' ');
	if (!av)
		return (ft_printf("Error\nCrash of Malloc.\n"));
	tab_to_pile(&a_pile, av);
	if (!a_pile)
		return (ft_printf("Error\nBad Input\n"), 1);
	if (!check_sort(a_pile))
	{
		if (ft_lstsize(a_pile) == 2)
			do_swap(&a_pile, &b_pile, 'a');
		if (ft_lstsize(a_pile) == 3)
			sort_three(&a_pile);
//		else
//			sort_algo(&a_pile, &b_pile);
	}
	print_list(&a_pile);
	free_bird(&a_pile, av);
	return (0);
}