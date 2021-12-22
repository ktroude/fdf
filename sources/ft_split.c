/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktroude <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:32:34 by ktroude           #+#    #+#             */
/*   Updated: 2021/12/22 16:56:18 by ktroude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_count_line_tab(char const *s, char c)
{
	int	i;
	int	secu;
	int	count;

	i = 0;
	secu = 0;
	count = 0;
	while ((size_t)i < ft_strlen(s))
	{
		if (s[i] == c)
			secu = 0;
		else if (!secu)
		{
			secu = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static void	ft_get_next_str(char **next_str, unsigned int *next_str_len, char c)
{
	unsigned int	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

typedef struct s_split {
	char			**tab;
	char			*next_str;
	unsigned int	n_slen;
	unsigned int	count;
	unsigned int	i;
}	t_split;

char	**ft_split(char *s, char c)
{
	t_split	spl;

	if (!s)
		return (NULL);
	spl.n_slen = 0;
	spl.i = 0;
	spl.count = ft_count_line_tab(s, c);
	spl.tab = (char **)malloc(sizeof(char *) * (spl.count + 1));
	if (!(spl.tab))
		return (NULL);
	spl.next_str = (char *)s;
	while (spl.i < spl.count)
	{
		ft_get_next_str(&spl.next_str, &spl.n_slen, c);
		spl.tab[spl.i] = (char *)malloc(sizeof(char) * (spl.n_slen + 1));
		if (!(spl.tab[spl.i]))
			return (ft_malloc_error(spl.tab));
		ft_strlcpy(spl.tab[spl.i++], spl.next_str, spl.n_slen + 1);
	}
	spl.tab[spl.i] = NULL;
	free(s);
	return (spl.tab);
}
