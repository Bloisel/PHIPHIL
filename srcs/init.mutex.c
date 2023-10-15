/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:25:30 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/15 02:36:57 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_mutex(t_p *p)
{
	int	i;

	i = -1;
	p->ph = malloc(sizeof(t_ph) * (p->dta.nb_philo));
	if (p->ph == NULL)
		return (1);
	while (++i < p->dta.nb_philo)
	{
		p->ph[i].nb_eat = 0;
		p->ph[i].num = i + 1;
		p->ph[i].end_all = 0;
		p->ph[i].last_eat_time = p->dta.start_time;
		pthread_mutex_init(&p->ph[i].l_fork, NULL);
		if (i == p->dta.nb_philo - 1)
			p->ph[i].r_fork = &p->ph[0].l_fork;
		else
			p->ph[i].r_fork = &p->ph[i + 1].l_fork;
	}
	// pthread_mutex_init(&p->dta.print_val, NULL);
	pthread_mutex_init(&p->dta.dont_print, NULL);
	pthread_mutex_init(&p->dta.dead, NULL);
	// pthread_mutex_init(&p->dta.time_eat, NULL);
	pthread_mutex_init(&p->dta.end_all, NULL);
	return (0);
}
