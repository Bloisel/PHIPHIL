/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:26:31 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/15 02:43:37 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*p_status(void *data)
{
	t_ph	*philo_struct;

	philo_struct = (t_ph *)data;
	// pthread_mutex_lock(&philo_struct->dta->end_all);
	// pthread_mutex_lock(&philo_struct->dta->print_val);
	if ((!p_status2(philo_struct, 0) && philo_struct->dta->t_t_die
			<= timeval() - philo_struct->last_eat_time))
	{
		// pthread_mutex_unlock(&philo_struct->dta->print_val);
		// pthread_mutex_unlock(&philo_struct->dta->end_all);
		print_val("is dead", philo_struct);
		p_status2(philo_struct, 5);
	}
	// pthread_mutex_unlock(&philo_struct->dta->print_val);
	// pthread_mutex_unlock(&philo_struct->dta->end_all);
	return (NULL);
}

void	after_eat(t_ph *ph)
{
	// pthread_mutex_lock(&ph->dta->print_val);
	print_val("is sleeping", ph);
	// pthread_mutex_unlock(&ph->dta->print_val);
	ft_usleep(ph->dta->t_t_sleep * 1000);
	// pthread_mutex_lock(&ph->dta->print_val);
	print_val("is thinking", ph);
	// pthread_mutex_unlock(&ph->dta->print_val);
}

void	is_eating(t_ph *ph)
{
	// pthread_mutex_lock(&ph->dta->print_val);
	// pthread_mutex_lock(&ph->dta->time_eat);
	print_val("is eating", ph);
	// pthread_mutex_unlock(&ph->dta->print_val);
	ph->last_eat_time = timeval();
	ph->nb_eat++;
	ft_usleep(ph->dta->t_t_eat * 1000);
	// pthread_mutex_unlock(&ph->dta->time_eat);
	//pthread_mutex_unlock(&ph->dta->print_val);
	//ft_usleep(ph->dta->t_t_eat * 1000);
	after_eat(ph);
	return ;
}

void	taking_fork(t_ph *ph)
{
	if (ph->dta->nb_philo == 1)
	{
		ft_usleep(ph->dta->t_t_die * 1000);
		return ;
	}
	pthread_mutex_lock(&ph->l_fork);
	print_val("has taken left fork", ph);
	pthread_mutex_lock(ph->r_fork);
	print_val("has taken right fork", ph);
	is_eating(ph);
	pthread_mutex_unlock(&ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
}

void	*philo(void *data)
{
	t_ph	*philo_struct;

	philo_struct = ((t_ph *)data);
	if (philo_struct->num % 2 == 0)
		ft_usleep(philo_struct->dta->t_t_eat * 1000);
	while (!p_status2(philo_struct, 0))
	{
		if (pthread_create(&philo_struct->th_check, NULL, p_status, data) != 0)
			return (NULL);
		taking_fork(philo_struct);
		pthread_detach(philo_struct->th_check);
		if (philo_struct->nb_eat == philo_struct->dta->nb_eat && philo_struct->dta->nb_philo != 1)
		{
			// pthread_mutex_lock(&philo_struct->dta->end_all);
			if (++philo_struct->dta->all_th_end == philo_struct->dta->nb_philo)
			{
				// pthread_mutex_unlock(&philo_struct->dta->end_all);
				p_status2(philo_struct, 5);
			}
			// pthread_mutex_unlock(&philo_struct->dta->end_all);
			return (NULL);
		}
	}
	return (NULL);
}
