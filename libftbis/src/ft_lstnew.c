/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:16:56 by grebrune          #+#    #+#             */
/*   Updated: 2024/03/01 19:42:47 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_pile	*ft_lstnew(void	*content)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (new == NULL)
		return (new);
	new->content = content;
	new->next = NULL;
	return (new);
}
