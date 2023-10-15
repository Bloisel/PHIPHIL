/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:27:03 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/15 02:36:52 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data
{
	int				nb_philo;
	int				t_t_die;
	int				t_t_eat;
	int				t_t_sleep;
	int				nb_eat;
	long int		start_time;
	// pthread_mutex_t	print_val;
	pthread_mutex_t	dead;
	// pthread_mutex_t	time_eat;
	pthread_mutex_t	end_all;
	pthread_mutex_t	dont_print;
	int				all_th_end;
	int				end;
	int				dont_print1;

}		t_data;

typedef struct s_ph
{
	pthread_t	th_id;
	pthread_t	th_check;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	l_fork;
	t_data	*dta;
	long int	last_eat_time;
	int	nb_eat;
	int	num;
	int	end_all;
}		t_ph;

typedef struct	s_p
{
	t_ph *ph;
	t_data dta;
}		t_p;

void	init_struct(t_p *p, char **argv);
int	init_mutex(t_p *p);
void	init_philo(t_p *p);
int	init_thread(t_p *p);
void	*p_status(void *data);
int	p_status2(t_ph *p, int i);
void	*philo(void *data);
void	ft_usleep(long long milis);
long long	timeval(void);
int	ft_atoi_mini(char *str);
int	check_ar(char **argv);
void	print_val(char *str, t_ph *ph);
void	after_eat(t_ph *ph);
int	free_resources(t_p *p);

#endif
