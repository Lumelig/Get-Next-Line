/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpflegha <jpflegha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:29:32 by jpflegha          #+#    #+#             */
/*   Updated: 2024/11/29 18:23:32 by jpflegha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	polish_list(t_list **list, char *remainder)
{
	t_list	*last_node;
	int		i;
	int		j;

	if (list == NULL || *list == NULL)
		return ;
	last_node = find_node((i = 0, j = 0, *list));
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		i++;
	if (last_node->str_buf[i] == '\n')
		i++;
	while (last_node->str_buf[i])
		remainder[j++] = last_node->str_buf[i++];
	remainder[j] = '\0';
	dealloc(list);
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
	{
		free(buffer);
		return ;
	}
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buffer;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		chars;
	char	*buffer;
	t_list	*tmp;

	tmp = NULL;
	while (!newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		chars = read(fd, buffer, BUFFER_SIZE);
		if (chars <= 0)
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
	t_list		*list;
	char		*newline;
	static char	remainder[BUFFER_SIZE + 1];

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &create_list, 0) < 0)
		return (dealloc(&list), remainder[0] = 0, NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	newline = get_newline(list);
	polish_list(&list, remainder);
	return (newline);
}

// int	main(void)
// {
// 	char	*line;
// 	int		fd;

// 	printf("execiting %d\n", BUFFER_SIZE);
// 	fd = open("test.txt", O_RDONLY, 0644);
// 	if (fd == -1)
// 		printf("err cannot read file\n");
// 	line = get_next_line(fd);
// 	printf(">>>%s", line);
// 	free(line);
// 	return (EXIT_SUCCESS);
// }
