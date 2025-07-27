/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushstrings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahhali <srahhali@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:26:35 by srahhali          #+#    #+#             */
/*   Updated: 2025/07/26 04:20:17 by srahhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "rushlib.h"

// Return a strndup-ed copy of the contents of the contents of the 
// string with both ends stripped of spaces. It does not remove
// spaces in the middle.
char	*ft_trim_extract(char *str, int *size)
{
	int		i;
	char	*ss;
	char	*se;
	char	*copy;

	ss = str;
	while (*ss && *ss == ' ')
		ss++;
	if (NULL == ss)
		return (NULL);
	i = 0;
	se = ft_strrchr(str, '\n');
	*size = se - ss;
	copy = ft_strndup(ss, *size);
	return (copy);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*copy;

	copy = (char *)malloc(sizeof(char) * ft_strlen(str));
	if (NULL == copy)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&(str[i]));
		i++;
	}
	return (NULL);
}

char	*ft_strrchr(char *str, char c)
{
	char	*found;
	int	i;

	i = 0;
	found = NULL;
	while (str[i])
	{
		if (str[i] == c)
			found = &(str[i]);
		i++;
	}
	return (found);
}
