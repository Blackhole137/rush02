/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahhali <srahhali@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:41:01 by srahhali          #+#    #+#             */
/*   Updated: 2025/07/26 18:32:18 by srahhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUCKET_COUNT 10

struct dict_elem
{
	char				*repr;
	unsigned long		*size;
	unsigned long		*number; // in rushlib ft_atoi_n returns signed longs
	struct dict_elem	*next;
};
