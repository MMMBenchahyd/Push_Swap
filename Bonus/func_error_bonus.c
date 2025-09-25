/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_error_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:29:36 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/19 14:44:28 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	handl_err_and_free(char **c)
{
	free(*c);
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

void	handl_err(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

void	free_stack_err(t_list **stack_a, t_list **stack_b, int flg)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	if (flg)
		handl_err();
}
