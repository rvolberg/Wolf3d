/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <tlaberro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:39:30 by tlaberro          #+#    #+#             */
/*   Updated: 2019/03/06 16:09:56 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_seglen(char *mem)
{
	unsigned int	i;

	i = 0;
	while (mem[i] != '\n' && mem[i] != '\0')
		i++;
	return (i);
}

static char				*ft_chrandcpy(char *mem)
{
	if (ft_strchr(mem, '\n') != NULL)
	{
		ft_strcpy(mem, ft_strchr(mem, '\n') + 1);
		return ("ok");
	}
	if (ft_seglen(mem) > 0)
	{
		ft_strcpy(mem, ft_strchr(mem, '\0'));
		return ("ok");
	}
	return (NULL);
}

int						get_next_line(int const fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*mem;
	int			ret;
	char		*ptr;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(mem))
		mem = ft_strnew(0);
	while ((ft_strchr(mem, '\n') == NULL)
		&& (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		ptr = mem;
		mem = ft_strjoin(ptr, buff);
		free(ptr);
	}
	*line = ft_strsub(mem, 0, ft_seglen(mem));
	if (ft_chrandcpy(mem) == NULL)
	{
		return (0);
	}
	return (1);
}
