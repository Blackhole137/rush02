/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srahhali <srahhali@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 22:57:06 by srahhali          #+#    #+#             */
/*   Updated: 2025/07/26 04:46:14 by srahhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "dict.h"

int	free_dict_list(struct dict_elem *head)
{
	struct dict_elem	*temp;
	int					i;

	i = 0;
	while (head)
	{
		free(head->repr);
		head->repr = NULL;
		temp = head;
		head = temp->next;
		free(temp);
		temp = NULL;
		i++;
	}
	return (i);
}

int	free_buckets(void)
{
	int					i;
	int					count;
	struct dict_elem	*head;

	i = 0;
	count = 0;
	while (i < BUCKET_COUNT)
	{
		if (g_dict_buckets[i] != NULL)
		{
			head = g_dict_buckets[i];
			count += free_dict_list(head);
		}
		g_dict_buckets[i] = NULL;
		g_dict_tails[i] = NULL;
		i++;
	}
	return (count);
}
