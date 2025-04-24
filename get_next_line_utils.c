/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:42:02 by dbriant           #+#    #+#             */
/*   Updated: 2025/04/24 23:34:55 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_copynewline(char *buff, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc((sizeof(char) * len) + 1);
	new[len] = '\0';
	while (i < len)
		new[i++] = *(buff++);
	buff = NULL;
	return (new);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	str = NULL;
	return (i);
}

static	char	*ft_createnewstr(ssize_t len)
{
	char	*new;

	new = malloc((sizeof(char) * len) + 1);
	while (len)
		new[len--] = '\0';
	return (new);
}

char	*ft_realloc(char *new, char *buff, ssize_t len)
{
	char	*old;
	size_t	i;
	size_t	b;
	size_t	strlen;

	i = 0;
	old = NULL;
	strlen = ft_strlen(new);
	if (new != NULL)
		old = new;
	b = ft_checkifnewline(buff);
	ft_cleanbuff(buff, len);
	len = len + strlen;
	if (b)
		len = b + strlen;
	new = ft_createnewstr(len);
	if (old == NULL)
		return (ft_strlcpy(new, buff, len));
	while (*old != '\0')
		new[i++] = *(old++);
	free(old - i);
	if (!b)
		b = len - strlen;
	ft_strlcpy(&(new[i]), buff, b);
	return (new);
}

void	ft_cleanbuff(char *buff, size_t size)
{
	size_t	buffsize;

	buffsize = BUFFER_SIZE;
	while (size < buffsize)
		buff[size++] = '\0';
}
