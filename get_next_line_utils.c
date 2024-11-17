#include "get_next_line.h"

int	count_newline(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	if (list == NULL)
		return (NULL);
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] = '\n')
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

void	cpy_line(t_list *list, char *newline)
{
	int	i;
	int	j;

	j = 0;
	if (list == NULL)
		return (NULL);
	while (list)
	{
		i = 0;
		while (list->str_buf[i])
		{
			if (list->str_buf[i] = '\n')
			{
				newline[j] = '\n';
				j++;
				newline[j] = '\0';
				return ; 
			}
			newline[j] = list->str_buf[i];
			i++;
			j++;
		}
		newline[j] = '\0';
	}
	
}