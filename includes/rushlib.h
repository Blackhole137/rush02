/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahhali <srahhali@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:27:51 by srahhali          #+#    #+#             */
/*   Updated: 2025/07/26 18:28:42 by srahhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

// rushstrings.c
int		ft_strlen(char *str);
char	*ft_strndup(char *str, int n);
char	*ft_strchr(char *str, char c);
char	*ft_strrchr(char *str, char c);
char	*ft_trim_extract(char *str, int *size);

// rushnumeric.c
long	ft_atol_n(char *str, int n);

// rushgetline.c
char	*ft_getline(int fd);
