/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:29:20 by jpflegha          #+#    #+#             */
/*   Updated: 2024/11/22 18:35:28 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	return ;
}

void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*new_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = malloc(sizeof(t_list));
	new_node = malloc(sizeof(t_list));
	if (buffer == NULL || new_node == NULL)
		return ;
	last_node = find_node(*list);
	i = 0;
	j = 0;
	while (last_node->str_buf[i] != '\0' && last_node->str_buf[i] != '\n')
		i++;
	while (last_node->str_buf[i] != '\0' && last_node->str_buf[++i])
		buffer[j++] = last_node->str_buf[i];
	buffer[j] = '\0';
	new_node->str_buf = buffer;
	new_node->next = NULL;
	dealloc(list, new_node, buffer);
}

int	newline(t_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		printf("hier");
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

void	dealloc(t_list **list, t_list *new_node, char *buffer)
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
	*list = NULL;
	if (new_node->str_buf[0])
		*list = new_node;
	else
	{
		free(buffer);
		free(new_node);
	}
	return ;
}
