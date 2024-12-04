/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:29:43 by jpflegha          #+#    #+#             */
/*   Updated: 2024/12/04 00:38:03 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> // for read
# include <stdlib.h> // for malloc
# include <stdio.h> // for printf and End Of File
# include <fcntl.h> // for open txt file
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int	ft_strlen(char *str);

char	*copy_line(char *buffer, char *newline);

char	*get_next_line(int fd);

int	newline_check(char *buffer);

void save_remainder(char	*buffer, char remainder[]);
#endif