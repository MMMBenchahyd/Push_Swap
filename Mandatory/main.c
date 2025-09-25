/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:30:40 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/19 16:50:35 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char	**argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc != 1)
	{
		if (ft_parcing(argc, argv, &stack_a) == 0)
		{
			write(2, "Error\n", 6);
			ft_free_stack(&stack_a);
			return (1);
		}
		ft_index(stack_a);
		if (!is_sorted(stack_a))
			ft_select_sort(&stack_a, &stack_b);
		ft_free_stack(&stack_b);
		ft_free_stack(&stack_a);
	}
	return (0);
}
