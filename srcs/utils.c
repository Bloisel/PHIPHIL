/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:26:42 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/15 02:36:46 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	timeval(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long long milis)
{
	long long	time;

	time = timeval() * 1000;
	while (1)
	{
		usleep(50);
		if (timeval() * 1000 - time >= milis)
			break ;
	}
}

void	print_val(char *str, t_ph *ph)
{
	long	ms;

	pthread_mutex_lock(&ph->dta->dont_print);
	ms = 0;
	ms = (timeval() - ph->dta->start_time);
	if (ms >= 0 && !p_status2(ph, 0))
		printf("%ld, %d, %s\n", ms, ph->num, str);
	pthread_mutex_unlock(&ph->dta->dont_print);
}

int	ft_atoi_mini(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = (res * 10) + str[i] - 48;
		i++;
	}
	return (res);
}

int	p_status2(t_ph *p, int i)
{
	pthread_mutex_lock(&p->dta->dead);
	if (i)
		p->dta->end = 1;
	if (p->dta->end)
	{
		pthread_mutex_unlock(&p->dta->dead);
		return (1);
	}
	pthread_mutex_unlock(&p->dta->dead);
	return (0);
}
