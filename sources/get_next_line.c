/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:28:17 by ktroude           #+#    #+#             */
/*   Updated: 2021/12/02 18:29:46 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 1

char	*ft_substr_v2(char *s, int start, int len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[start] && i < len)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}

char	*cut_line(char **str, int pos)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_substr_v2(*str, 0, pos + 1);
	pos++;
	if (ft_strlen_v2(*str + pos) > 0)
	{
		*str = ft_memmove_v2(*str, *str + pos, ft_strlen_v2(*str + pos) + 1);
	}
	else
	{
		free(*str);
		*str = NULL;
	}
	return (line);
}

char	*no_new_line(char **str)
{	
	char	*line;

	line = ft_strdup_v2(*str);
	free(*str);
	*str = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*str = NULL;
	int			ret;
	int			pos;

	if (str)
	{
		pos = ft_strchr_v2(str, '\n');
		if (pos != -1)
			return (cut_line(&str, pos));
	}
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0 && str == NULL)
			return (NULL);
		buf[ret] = 0;
		str = ft_strjoin_v2(str, buf);
		pos = ft_strchr_v2(str, '\n');
		if (pos != -1)
			return (cut_line(&str, pos));
	}
	return (no_new_line(&str));
}
/*
int	main()
{
	int	fd;

	fd = open("coucou", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
}
*/
