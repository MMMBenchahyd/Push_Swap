/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:29:36 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/09 18:29:37 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
