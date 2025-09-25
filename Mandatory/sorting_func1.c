/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:35:11 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/11 17:22:46 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first > second && first < third)
		ft_sa(stack_a);
	if (second < first && second > third)
	{
		ft_sa (stack_a);
		ft_rra(stack_a);
	}
	if (third > second && third < first)
		ft_ra(stack_a);
	if (third < second && third > first)
	{
		ft_sa (stack_a);
		ft_ra (stack_a);
	}
	if (first > third && first < second)
		ft_rra (stack_a);
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 4)
	{
		ft_stack_push(stack_a, stack_b, ft_find_min((*stack_a)), 1);
		ft_sort_3(stack_a);
		ft_pa(stack_a, stack_b);
	}
	else if (ft_lstsize(*stack_a) == 5)
	{
		ft_stack_push(stack_a, stack_b, ft_find_min((*stack_a)), 0);
		ft_stack_push(stack_a, stack_b, ft_find_min((*stack_a)), 1);
		ft_sort_3(stack_a);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
	}
}

int	ft_find_min(t_list *stack_a)
{
	int		min;
	int		i;
	int		j;

	min = stack_a->content;
	i = 1;
	while (stack_a)
	{
		if (min > stack_a->content)
		{
			j = i;
			min = stack_a->content;
		}
		i++;
		stack_a = stack_a->next;
	}
	return (j);
}

void	ft_stack_push(t_list **stack_a, t_list **stack_b, int min, int flg)
{
	if (min == 1)
		ft_pb(stack_a, stack_b);
	else if (min == 2)
	{
		ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else if (min == 3)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else if (min == 4 && flg == 0)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else if (min == (5 - flg))
	{
		ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
}
