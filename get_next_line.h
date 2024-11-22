#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // for read
# include <stdlib.h> // for malloc
# include <stdio.h> // for printf and End Of File
# include <fcntl.h> // for open txt file
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}	t_list;

void	dealloc(t_list **list, t_list *new_node, char *buffer);

char	*get_next_line(int fd);

void	creat_list(t_list **list, int fd);

void	append(t_list **list, char *buffer);

char	*get_line(t_list *list);

int	newline(t_list *list);

t_list	*find_node(t_list *list);

void	polish_list(t_list **list);

void	cpy_line(t_list *list, char *newline);

int	count_newline(t_list *list);
#endif