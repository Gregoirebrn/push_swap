/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:44:09 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/08 18:08:05 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libftbis/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_sort
{
	size_t	i;
	size_t	len;
	int		bit;
	t_pile	*parse;
	int		len_b;
}	t_sort;

void	ft_swap(t_pile **lst);
void	ft_push(t_pile **a, t_pile **b);
void	ft_rotate(t_pile **lst);
void	ft_rev_rot(t_pile **lst);

void	do_swap(t_pile **a, t_pile **b, char c);
void	do_push(t_pile **a, t_pile **b, char c);
void	do_rotate(t_pile **a, t_pile **b, char c);
void	do_rev_rot(t_pile **a, t_pile **b, char c);

int		tab_to_pile(t_pile **a_pile, char **tab);
size_t	tab_len(char **tab);

void	sort_algo(t_pile **a, t_pile **b);
void	sort_five(t_pile **a_pile, t_pile **b_pile);
void	sort_three(t_pile **a_pile);
int		biggest_nbr(t_pile **a_pile);
int		check_sort(t_pile *a);
void	sort_rank(t_pile **a_pile);

void	init_five(t_pile **a_pile);

void	free_bird(t_pile *a, char **av);

void	print_list(t_pile **a);

#endif