/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:29:47 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/08 21:42:18 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_av(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_bird(t_pile *a, char **av)
{
	t_pile	*tmp;

	if (av && (ft_strncmp(av[0], "./push_swap", 10) != 0))
		free_av(av);
	tmp = a;
	while (a)
	{
		tmp = tmp->next;
		free(a);
		a = tmp;
	}
}

void	find_size(t_pile **a_pile, t_pile **b_pile)
{
	size_t	size;

	size = ft_lstsize(*a_pile);
	if (size == 2)
		do_swap(a_pile, b_pile, 'a');
	else if (size == 3)
		sort_three(a_pile);
	else if (size <= 5)
		sort_five(a_pile, b_pile);
	else
		sort_algo(a_pile, b_pile);
}

int	check_args(char **av)
{
	size_t	i;
	size_t	x;

	x = 0;
	if (ft_strncmp(av[x], "./push_swap", 10) == 0)
		x = 1;
	while (av[x])
	{
		i = 0;
		while (av[x][i])
		{
			if ((av[x][i] != '-' && av[x][i] != '+')
			&& !(av[x][i] >= '0' && av[x][i] <= '9'))
				return (1);
			if ((av[x][i] == '-' || av[x][i] == '+')
			&& !(av[x][i + 1] >= '0' && av[x][i + 1] <= '9'))
				return (1);
			i++;
		}
		x++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_pile	*a_pile;
	t_pile	*b_pile;

	a_pile = NULL;
	b_pile = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	if (!av)
		return (ft_printf("Error\nCrash of Malloc.\n"), 1);
	if (check_args(av) == 1)
		return (ft_printf("Error\nArgument different from a number.\n"), 1);
	if (tab_to_pile(&a_pile, av))
		return (free_bird(a_pile, av), 1);
	if (!check_sort(a_pile))
		find_size(&a_pile, &b_pile);
	return (free_bird(a_pile, av), 0);
}
