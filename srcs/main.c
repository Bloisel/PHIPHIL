/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:26:19 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/14 07:04:19 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_ar(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_p	p;

	if ((check_ar(argv) == 1) || (argc != 6 && argc != 5))
		return (1);
	init_struct(&p, argv);
	init_mutex(&p);
	init_thread(&p);
	// system("leaks Philosopher");
	if (free_resources(&p) != 0)
			return (1);
	return (0);	
}
