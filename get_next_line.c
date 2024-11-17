#include "get_next_line.h"

char	*get_line(t_list *list)
{
	int		len;
	char	*newline;

	len = 0;
	if (list == NULL)
		return (NULL);
	len = count_to_newline(list);
	newline = malloc(len + 1);
	if (newline = NULL)
		return (NULL);
	copy_line(newline);
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
	else
		last_node->next = new_node;
	last_node->str_buf = buffer;
	new_node->next = NULL;
}

void	creat_list(t_list **list, int fd)
{
	int		chars;
	char	*buffer

	while (!newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
	}
	chars = read(fd, buffer, BUFFER_SIZE);
	if (!chars)
	{
		free(buffer);
		return ;
	}
	buffer[chars] = '\0';
	append(list, buffer);
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
	newline = get_line(list);
	polish_list(&list);
	return (newline);
}