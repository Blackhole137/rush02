/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushnumeric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahhali <srahhali@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:49:54 by srahhali          #+#    #+#             */
/*   Updated: 2025/07/26 13:02:07 by srahhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol_n(const char *str, int n)
{
	int				i;
	int				is_negative;
	long			result;

	i = 0;
	result = 0;
	is_negative = 0;
	while (i < n && str[i] && (str[i] == ' '
			|| (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	if (str[i] == '-' || str[i] == '+' || i >= n)
		if (str[i++] == '-' || i >= n)
			return (-1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}
