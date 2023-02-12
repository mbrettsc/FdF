/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:56:07 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/02/09 17:20:50 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

void	push(t_coord_value **stack, t_coord_value *new)
{
	if (!new)
		return ;
	new->next = *stack;
	*stack = new;
}

t_coord_value	*pop(t_coord_value **stack)
{
	t_coord_value	*ret;

	ret = NULL;
	if (*stack)
	{
		ret = *stack;
		*stack = (*stack)->next;
	}
	return (ret);
}
