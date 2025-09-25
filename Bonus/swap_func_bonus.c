/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:35:20 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/19 16:45:25 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_sa(t_list **stack_a)
{
	t_list	tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	ft_memcpy((void *)&tmp, (void *)(*stack_a), 8);
	ft_memcpy((void *)(*stack_a), (void *)(*stack_a)->next, 8);
	ft_memcpy((void *)(*stack_a)->next, (void *)&tmp, 8);
}

void	ft_sb(t_list **stack_a)
{
	t_list	tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	ft_memcpy((void *)&tmp, (void *)(*stack_a), 8);
	ft_memcpy((void *)(*stack_a), (void *)(*stack_a)->next, 8);
	ft_memcpy((void *)(*stack_a)->next, (void *)&tmp, 8);
}

void	ft_ss(t_list **stack_b, t_list **stack_a)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}
