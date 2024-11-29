/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:29:20 by jpflegha          #+#    #+#             */
/*   Updated: 2024/11/29 18:10:33 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*find_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	count_newline(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		list = list->next;
	}
	return (len);
}

void	copy_line(t_list *list, char *newline)
{
	int	i;
	int	j;

	j = 0;
	if (list == NULL)
		return ;
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				newline[j] = '\n';
				j++;
				newline[j] = '\0';
				return ;
			}
			newline[j++] = list->str_buf[i++];
		}
		list = list->next;
	}
	newline[j] = '\0';
}

int	newline(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buf[i] && i < BUFFER_SIZE)
		{
			if (list->str_buf[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

void	dealloc(t_list **list)
{
	t_list	*tmp;

	if (list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buf);
		free(*list);
		*list = tmp;
	}
	return ;
}
