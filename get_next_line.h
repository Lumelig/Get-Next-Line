/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:29:43 by jpflegha          #+#    #+#             */
/*   Updated: 2024/12/16 12:40:04 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <unistd.h> // for read
# include <stdlib.h> // for malloc
# include <stdio.h> // for printf and End Of File
# include <fcntl.h> // for open txt file
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


void	free_and_null(char **ptr);

char	*extract_line(char *remainder);

void	update_remainder(char *remainder);

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *s, int c);

void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strncat(char *dest, const char *src, size_t n);

#endif