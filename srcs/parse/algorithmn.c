/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:50:50 by mtavares          #+#    #+#             */
/*   Updated: 2023/04/17 19:58:49 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	string_unique_char(char *s)
{
	int	result[4];
	int	i;

	i = -1;
	while (++i < 4)
		result[i] = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == 'N')
			result[0]++;
		else if (s[i] == 'S')
			result[1]++;
		else if (s[i] == 'W')
			result[2]++;
		else if (s[i] == 'E')
			result[3]++;
	}
	i = -1;
	while (++i < 4)
		if (result[i] != 1)
			return (0);
	return (1);
}
