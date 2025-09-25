/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:33:55 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/10 20:57:14 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	r_func(t_list **stack_ptr)
{
	t_list	*ptr;

	ptr = ft_lstlast(*stack_ptr);
	ptr->next = *stack_ptr;
	*stack_ptr = (*stack_ptr)->next;
	ptr->next->next = NULL;
}

void	ft_ra(t_list **stack_a)
{
	if (*stack_a)
		r_func(stack_a);
}

void	ft_rb(t_list **stack_b)
{
	if (*stack_b)
		r_func(stack_b);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra (stack_a);
	ft_rb (stack_b);
}
