/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:00:16 by dbriant           #+#    #+#             */
/*   Updated: 2025/05/09 15:00:18 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclength;
	size_t	i;

	srclength = ft_strlen(src);
	i = 0;
	if (!size || src == NULL || dst == NULL)
		return (srclength);
	while ((i < size - 1) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	length;
	void	*str;

	length = nmemb * size;
	str = malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	else if (!nmemb || !size)
		return (str);
	while (length)
	{
		((char *)str)[length - 1] = '\0';
		length--;
	}
	return (str);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	target;

	target = c;
	if (s == NULL)
		return (NULL);
	while (n != 0 && (*(char *)s != '\0'))
	{
		if (*(unsigned char *)s == target)
			return ((char *)s);
		n--;
		s++;
	}
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen((char *)src);
	i = dstlen;
	if (size <= dstlen)
		return (size + srclen);
	while (*src && (dstlen + 1 < size))
	{
		dst[dstlen] = *src;
		dstlen++;
		src++;
	}
	dst[dstlen] = '\0';
	return (i + srclen);
}
