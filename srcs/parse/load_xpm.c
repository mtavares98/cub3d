/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:22:59 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/17 14:00:37 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

void	verify_paths(t_cub *data, char **path)
{
	int		i;
	int		j;
	int		fd;
	char	*delims;

	delims = "NSEW";
	i = -1;
	while (data->img.order[++i])
	{
		j = -1;
		while (delims[++j])
			if (data->img.order[i] == delims[j])
				exit_free(data, 1, "Has equal variables on order");
	}
	i = -1;
	while (path[++i])
		open_file(data, path[i]);
}
