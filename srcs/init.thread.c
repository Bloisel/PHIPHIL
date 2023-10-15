/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:26:10 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/14 00:05:12 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_thread(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->dta.nb_philo)
	{
		p->ph[i].dta = &p->dta;
		if (pthread_create(&p->ph[i].th_id, NULL, philo, &p->ph[i]) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i < p->dta.nb_philo)
	{
		if (pthread_join(p->ph[i].th_id, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}
