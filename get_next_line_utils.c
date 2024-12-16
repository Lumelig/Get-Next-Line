/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jenne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:29:20 by jpflegha          #+#    #+#             */
/*   Updated: 2024/12/16 12:35:17 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cc;
	char			*cs;

	cs = (char *)s;
	cc = (char)c;
	while (*cs)
	{
		if (*cs == cc)
			return (cs);
		cs++;
	}
	if (cc == '\0')
		return (cs);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	free_and_null(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;
	size_t		a;

	dest_ptr = dst;
	src_ptr = src;
	a = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (a < n)
	{
		dest_ptr[a] = src_ptr[a];
		a++;
	}
	return (dst);
}

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	dest_len;
	size_t	i;

	// Find end of destination string
	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;

	// Copy characters from source
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}

	// Null-terminate the result
	dest[dest_len + i] = '\0';

	return (dest);
}
