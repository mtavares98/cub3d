/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:41:36 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/01 01:26:41 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>

static int	counting_lines(t_parse *parse, int y)
{
	int	count_lines;
	int	j;

	count_lines = 0;
	while (parse->file[y])
	{
		j = -1;
		while (parse->file[y][++j])
		{
			if (!string().ft_isspace(parse->file[y][j]) && parse->file[y][j])
			{
				count_lines++;
				break ;
			}
		}
		y++;
	}
	return (count_lines);
}

void	get_map(t_cub *data, t_parse *parse, int y)
{
	int	i;
	int	j;
	int	num_lines;

	num_lines = counting_lines(parse, y);
	data->map.map = alloc().calloc(sizeof(char *) * (num_lines + 1));
	if (!data->map.map)
	{
		free_parse(parse);
		exit_free(data, 1, "Error malloc with map");
	}
	i = -1;
	while (parse->file[y])
	{
		j = -1;
		while (parse->file[y][++j])
		{
			if (!string().ft_isspace(parse->file[y][j]) && parse->file[y][j])
			{
				data->map.map[++i] = string().strdup(parse->file[y]);
				break ;
			}
		}
		y++;
	}
}

void	parse_file(t_cub *data, t_parse *parse)
{
	int	y;
	int	i;

	y = get_vars(data, parse);
	i = -1;
	while (parse->path_to_img[++i])
		;
	if (i != 4)
	{
		free_parse(parse);
		exit_free(data, 1, "must contain NO SO WE EA path to the files");
	}
	get_map(data, parse, y);
	if (format_map(this_cub()))
	{
		free_parse(parse);
		exit_free(this_cub(), 1, "Error malloc new str");
	}
}
