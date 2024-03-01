/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:44:09 by grebrune          #+#    #+#             */
/*   Updated: 2024/02/12 21:58:01 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libftbis/libft.h"

typedef struct s_pile
{
	int				*content;
	struct s_pile	*next;
}t_pile;

void	ft_swap(t_pile **lst);
void	ft_push(t_pile **a, t_pile **b);
void	ft_rotate(t_pile **lst);
void	ft_rev_rot(t_pile **lst);

#endif