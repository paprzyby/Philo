/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:17:22 by paprzyby          #+#    #+#             */
/*   Updated: 2024/11/13 14:17:25 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*checker_function(void *arg)
{
	t_data *data = (t_data *)arg;
	(void)data;
	printf("checker function\n");
	return (0);
}
