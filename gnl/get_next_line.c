/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:29:32 by jpflegha          #+#    #+#             */
/*   Updated: 2024/12/04 00:37:20 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	save_remainder(char	*buffer, char *remainder[])
{
	// char	*remainder;
	int		j;
	int		i;
	
	i = 0;
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
		j++;
	// if (!buffer[j])
	// 	return (NULL);
	// remainder = malloc(BUFFER_SIZE - j + 1);
	// if (!remainder)
	// 	return NULL;
	j++;
	while (buffer[j])
		(*remainder)[i++] = buffer[j++];
	(*remainder)[i] = '\0';
	// return (remainder);
}

int	newline_check(char *newline)
{
	int	i;

	i = 0;
	if (!newline)
		return (0);
	while (newline[i])
	{
		if (newline[i] == '\n')
			return (1);	
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];
	char		*buffer;
	char		*newline;
	int			rl;

	
	newline = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	//
	if	(fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	if (remainder)
	{
		newline = copy_line(remainder, NULL);
		// free(remainder);
	}
	while (!newline_check(newline))
	{
	rl = read(fd, buffer, BUFFER_SIZE);
	if (rl <= 0)
		return (free(buffer), newline);
	buffer[rl] = '\0';
	newline = copy_line(buffer, newline);
	}
	return (save_remainder(buffer, &remainder), free(buffer), newline);
}

int main()
{
    int fd;
    int lines;
    char *newline;

    lines = 1;
    fd = open("test.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return (1);
    }

    while ((newline = get_next_line(fd)) != NULL) // Safely assign and check
    {
        //printf("%d --> %s\n", lines++, newline);
		printf("line: %s\n", newline);
        free(newline); // Free memory allocated by get_next_line
    }

    close(fd); // Close the file descriptor
    return (0);
}
