/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:29:20 by jpflegha          #+#    #+#             */
/*   Updated: 2024/12/04 00:21:05 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;
	
	len = 0;
	while (str && *str++)
		len++;
	return (len);
}

char	*copy_line(char *buffer, char *newline)
{
	int 	i;
	int		j;
	char	*new_string;
	
	i = 0;
	j = 0;\
// ft_str
	new_string = malloc(ft_strlen(newline) + BUFFER_SIZE + 1);
	while (newline && newline[j])
	{
		new_string[j] = newline[j];
		j++; 
	}
	while (buffer[i])
	{
		new_string[j++] = buffer[i++];
		if (new_string [j] == '\n')
			break;
			//'\0'
	}
	new_string[++j] = '\0';
	return (new_string);
	
}
