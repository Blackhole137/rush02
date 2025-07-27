/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahhali <srahhali@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:22:09 by srahhali          #+#    #+#             */
/*   Updated: 2025/07/26 04:46:10 by srahhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "rushlib.h"

void	init_buckets(void)
{
	int	i;

	i = 0;
	while (i < BUCKET_COUNT)
	{
		g_dict_buckets[i] = NULL;
		g_dict_tails[i]   = NULL;
		i++;
	}
}

struct dict_elem	*create_elem(char *dict_line)
{
	struct dict_elem	*elem;
	char				*repr;

	elem = (struct dict_elem)malloc(sizeof(struct dict_elem));
	if (NULL == elem)
		return (NULL);
	elem->next = NULL;
	elem->repr = ft_trim_extract(ft_strchr(dict_line, ':'), &(elem->size));
	elem->number = ft_atoi_n(elem->repr, (elem->repr) - (ft_strchr(elem, ':')));
	return (elem);
}

int	fill_dict_buckets(int fd)
{
	int					count;
	char				*line;
	struct dict_elem	*elem;

	count = 0;
	// TODO: create ft_getline
	line = ft_getline(fd);
	elem = create_elem(line);
	free(line);
	return (count);
}

