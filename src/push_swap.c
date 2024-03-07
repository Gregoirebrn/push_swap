/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:29:47 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/07 17:49:42 by grebrune         ###   ########.fr       */
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

	if (av && (ft_strncmp(av[0], "./push_swap", 10) != 0))
		free_av(av);
	tmp = (*a);
	while (*a)
	{
		tmp = tmp->next;
		free(*a);
		(*a) = tmp;
	}
}

void	find_size(t_pile *a_pile, t_pile *b_pile)
{
	size_t	size;

	size = ft_lstsize(a_pile);
	if (size == 2)
		do_swap(&a_pile, &b_pile, 'a');
	if (size == 3)
		sort_three(&a_pile);
	if (size == 5)
		sort_five(&a_pile, &b_pile);
	else
		sort_algo(&a_pile, &b_pile);
}

void	print_list(t_pile **a)
{
	int		i;
	t_pile	*parkour;

	if (!*a)
	{
		printf("list null\n");
		return ;
	}
	parkour = *a;
	i = 0;
	while (parkour->next != NULL)
	{
		ft_printf("content %d = %d\n", i, parkour->content);
//		ft_printf("rank %d = %d\n", i, parkour->rank);
		parkour = parkour->next;
		i++;
	}
	ft_printf("content %d = %d\n", i, parkour->content);
//	ft_printf("rank %d = %d\n", i, parkour->rank);
}

int	main(int ac, char **av)
{
	t_pile	*a_pile;
	t_pile	*b_pile;

	a_pile = NULL;
	b_pile = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (ft_printf("Error\nMissing Args.\n"), 1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	if (!av)
		return (ft_printf("Error\nCrash of Malloc.\n"), 1);
	if (tab_to_pile(&a_pile, av))
		return (free_bird(&a_pile, av), 1);
	print_list(&a_pile);
	if (!check_sort(a_pile))
		find_size(a_pile, b_pile);
	print_list(&a_pile);
	return (free_bird(&a_pile, av), 0);
}
