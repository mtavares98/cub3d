/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:39:49 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/31 21:16:42 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_cub	*this_cub(void)
{
	static t_cub	data;

	return (&data);
}

int	main(int ac, char **av)
{
	char	**path;

	(void)ac;
	(void)av;
	if (ac != 2)
		exit_free(NULL, 1, "Wrong number of arguments");
	path = parse(this_cub(), av[1]);
	if (check_map(this_cub(), path))
	{
		alloc().free_matrix((void **)path);
		exit_free(this_cub(), 1, "Error with map");
	}
	if (prep_alg(this_cub()))
	{
		alloc().free_matrix((void **)path);
		exit_free(this_cub(), 1, "Map is open");
	}
	alloc().free_matrix((void **)path);
	exit_free(this_cub(), 0, "Terminated");
}
