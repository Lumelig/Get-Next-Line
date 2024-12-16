/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:29:32 by jpflegha          #+#    #+#             */
/*   Updated: 2024/12/16 12:40:03 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *remainder)
{
	char	*line;
	int		len;

	if (!remainder || !remainder[0])
		return (NULL);

	len = 0;
	while (remainder[len] && remainder[len] != '\n')
		len++;
	
	if (remainder[len] == '\n')
		len++;

	line = malloc(len + 1);
	if (!line)
		return (NULL);

	ft_memcpy(line, remainder, len);
	line[len] = '\0';

	return (line);
}

void	update_remainder(char *remainder)
{
	int		line_end;
	int		remaining_len;
	char	temp[BUFFER_SIZE + 1];

	line_end = 0;
	while (remainder[line_end] && remainder[line_end] != '\n')
		line_end++;

	if (!remainder[line_end])
	{
		remainder[0] = '\0';
		return;
	}

	line_end++;
	remaining_len = ft_strlen(remainder + line_end);
	
	ft_memcpy(temp, remainder + line_end, remaining_len);
	temp[remaining_len] = '\0';
	
	ft_memcpy(remainder, temp, remaining_len + 1);
}

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	while (1)
	{
		// If remainder has a complete line, extract and update
		if (ft_strchr(remainder, '\n'))
		{
			line = extract_line(remainder);
			update_remainder(remainder);
			return (line);
		}

		// Read from file
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			// Last line without newline or error
			if (remainder[0])
			{
				line = extract_line(remainder);
				remainder[0] = '\0';
				return (line);
			}
			return (NULL);
		}

		buffer[bytes_read] = '\0';

		// Append buffer to remainder
		ft_strncat(remainder, buffer, BUFFER_SIZE);
	}
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
