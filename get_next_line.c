/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:29:32 by jpflegha          #+#    #+#             */
/*   Updated: 2024/11/23 15:49:44 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*new_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (buffer == NULL || new_node == NULL)
		return ;
	last_node = find_node(*list);
	i = 0;
	j = 0;
	while (last_node->str_buf[i] != '\0' && last_node->str_buf[i] != '\n')
		i++;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buffer[j++] = last_node->str_buf[i];
	buffer[j] = '\0';
	new_node->str_buf = buffer;
	new_node->next = NULL;
	dealloc(list, new_node, buffer);
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
