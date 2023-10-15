/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:26:00 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/14 00:03:14 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_struct(t_p *p, char **argv)
{
	p->dta.nb_philo = ft_atoi_mini(argv[1]);
	p->dta.t_t_die = ft_atoi_mini(argv[2]);
	p->dta.t_t_eat = ft_atoi_mini(argv[3]);
	p->dta.t_t_sleep = ft_atoi_mini(argv[4]);
	if (argv[5])
		p->dta.nb_eat = ft_atoi_mini(argv[5]);
	else
		p->dta.nb_eat = 0;
	p->dta.start_time = timeval();
	p->dta.all_th_end = 0;
	p->dta.end = 0;
	p->dta.dont_print1 = 0;
}
