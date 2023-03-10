/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:23:50 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/30 20:24:53 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

char	*get_next_line(int fd)
{
	int			byte_read;
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	byte_read = 1;
	while (1)
	{
		if (!buff[0])
			byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read > 0)
			line = ft_get_line(buff, line);
		if (ft_checknl(buff) || byte_read < 1)
			break ;
	}
	return (line);
}
