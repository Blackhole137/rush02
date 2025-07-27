/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushgetline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahhali <srahhali@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:23:57 by srahhali          #+#    #+#             */
/*   Updated: 2025/07/26 18:44:54 by srahhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include "rushlib.h"

#define GETLINE_BUFSIZE 0x800

unsigned int	g_getline_buffer_size;
char			*g_getline_buffer;
char			*g_getline_cursor;
unsigned int	g_line_counter;

char	*ft_getline_setup(void)
{
	g_getline_buffer_size = GETLINE_BUFSIZE;
	g_getline_cursor = NULL;
	g_getline_buffer = (char *)malloc(g_getline_buffer_size);
	if (NULL == g_getline_buffer)
		return (g_getline_buffer);
	g_getline_cursor = g_getline_buffer;
	g_line_counter = 0;
	return (g_getline_buffer);
}

void ft_getline_free(void)
{
	free(g_getline_buffer);
	g_getline_buffer = NULL;
	g_getline_cursor = NULL;
	g_getline_buffer_size = 0;
}

char	*ft_shift_buffer_left(void)
{
	unsigned int	bytes_left;
	unsigned int	used;
	unsigned int	i;

	used = g_getline_cursor - g_getline_buffer;
	bytes_left = GETLINE_BUFSIZE - used;	
	i = 0;
	while (i < bytes_left)
	{
		g_getline_buffer[i] = g_getline_cursor[i];
		i++;
	}
	while (i < g_getline_buffer_size)
		g_getline_buffer[i++] = 0;
	return (g_getline_buffer + used);
}

char	*ft_readline(int fd)
{
	int				read_amount;
	char			*newline;
	unsigned int	free_space

	free_space = GETLINE_BUFSIZE - (g_getline_cursor - g_getline_buffer);
	read_amount = read(fd, g_getline_cursor, free_space);
	newline = ft_strchr(g_getline_buffer, '\n');
	while (NULL == newline)
	{
		if (g_getline_cursor - g_getline_buffer == GETLINE_BUFSIZE
			&&read_amount > 0 && (unsigned int)read_amount < free_space)
			return ((char *)0);
		g_getline_cursor = ft_shift_buffer_left();
		read_amount = read(fd, g_getline_cursor, free_space);
		newline = ft_strchr(g_getline_buffer, '\n');
	}
	return (ft_strndup(g_getline_cursor, newline - g_getline_cursor));
}

char	*ft_getline(int fd)
{
	char	*result;
	if (NULL == g_getline_buffer)
		ft_getline_setup();
	result = ft_readline(fd);
	return (result);
}
