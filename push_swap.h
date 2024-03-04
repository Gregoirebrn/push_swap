/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:44:09 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/04 19:55:51 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libftbis/libft.h"
#include "ft_printf/ft_printf.h"
#include <limits.h>

void	ft_swap(t_pile **lst);
void	ft_push(t_pile **a, t_pile **b);
void	ft_rotate(t_pile **lst);
void	ft_rev_rot(t_pile **lst);

void	do_swap(t_pile **a, t_pile **b, char c);
void	do_push(t_pile **a, t_pile **b, char c);
void	do_rotate(t_pile **a, t_pile **b, char c);
void	do_rev_rot(t_pile **a, t_pile **b, char c);

int		check_sort(t_pile *a);

void	sort_three(t_pile **a_pile);
void	*biggest_nbr(t_pile **a_pile);

void	tab_to_pile(t_pile **a_pile, char **tab);
size_t	tab_len(char **tab);

void	sort_algo(t_pile **a, t_pile **b);

void	print_list(t_pile **a);

#endif