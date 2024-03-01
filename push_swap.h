/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:44:09 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/01 15:28:42 by grebrune         ###   ########.fr       */
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

#endif