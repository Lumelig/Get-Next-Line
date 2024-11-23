/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:29:32 by jpflegha          #+#    #+#             */
/*   Updated: 2024/11/23 15:36:53 by jenne            ###   ########.fr       */
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

char	*get_newline(t_list *list)
{
	int		len;
	char	*newline;

	len = 0;
	if (list == NULL)
		return (NULL);
	len = count_newline(list);
	newline = malloc(len + 1);
	if (newline == NULL)
		return (NULL);
	copy_line(list, newline);
	return (newline);
}

void	append(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buffer;
	new_node->next = NULL;
}

void	creat_list(t_list **list, int fd)
{
	int		chars;
	char	*buffer;

	while (!newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		chars = read(fd, buffer, BUFFER_SIZE);
		if (!chars)
		{
			free(buffer);
			return ;
		}
		buffer[chars] = '\0';
		append(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*newline;

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &get_next_line, 0) < 0)
		return (NULL);
	creat_list(&list, fd);
	if (list == NULL)
		return (NULL);
	newline = get_newline(list);
	polish_list(&list);
	return (newline);
}

// int	main()
// {
// 	int		fd;
// 	int		lines;
// 	char	*newline;

// 	lines = 1;
// 	fd = open("test.txt", O_RDONLY);
// 	while ((newline = get_next_line(fd)) != NULL)
// 		printf("%d -->  %s \n", lines++, newline);
// 	return (0);
// }
