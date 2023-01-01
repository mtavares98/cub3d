/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:34:44 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/31 18:00:37 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

static int	count_num_spaces(char *s)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '\t')
			len += 8;
		else
			len++;
	}
	return (len);
}

void	copy_new_str(t_cub *data, char *tmp, int i)
{
	int	j;
	int	k;
	int	l;

	j = -1;
	l = 0;
	while (data->map.map[i][++j])
	{
		if (data->map.map[i][j] == '\t')
		{
			k = -1;
			while (++k < 8)
				tmp[l++] = ' ';
		}
		else
			tmp[l++] = data->map.map[i][j];
	}
}

int	format_map(t_cub *data)
{
	int		i;
	int		len;
	char	*tmp;

	i = -1;
	while (data->map.map[++i])
	{
		len = count_num_spaces(data->map.map[i]);
		tmp = alloc().calloc(len + 1);
		if (!tmp)
			return (1);
		copy_new_str(data, tmp, i);
		if (data->map.map[i])
			alloc().free_array(data->map.map[i]);
		data->map.map[i] = tmp;
	}
	return (0);
}
