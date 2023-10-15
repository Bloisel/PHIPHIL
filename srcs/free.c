/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:25:43 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/15 02:37:08 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	free_resources(t_p *p)
{
	int	i;

	i = -1;
	while (++i < p->dta.nb_philo)
	{
		if (pthread_mutex_destroy(p->ph[i].r_fork) != 0)
			return (1);
		if (pthread_mutex_destroy(&p->ph[i].l_fork) != 0)
			return (1);
	}
	// if (pthread_mutex_destroy(&p->dta.print_val) != 0)
	// 	return (1);
	if (pthread_mutex_destroy(&p->dta.dead) != 0)
		return (1);
	if (pthread_mutex_destroy(&p->dta.dont_print) != 0)
		return (1);
	// if (pthread_mutex_destroy(&p->dta.time_eat) != 0)
	// 	return (1);
	if (pthread_mutex_destroy(&p->dta.end_all) != 0)
		return (1);
	return (0);
}
