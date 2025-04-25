/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:15:42 by dbriant           #+#    #+#             */
/*   Updated: 2025/04/25 08:12:57 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*ft_strlcpy(char *dest, char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dest == NULL)
		return (NULL);
	while ((i < len) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	src = NULL;
	return (dest);
}

size_t	ft_checkifnewline(char *buff)
{
	size_t	len;

	len = 0;
	while (buff[len] != '\0')
	{
		//printf("Index: %ld, buff: %c\n", len, buff[len]);
		if (buff[len] == '\n')
			return (++len);
		len++;
	}
	buff = NULL;
	return (0);
}

static	size_t	ft_checkcurrentbuff(char *buff)
{
	size_t	isnewline;
	size_t	i;
	char	*temp;

	i = 0;
	isnewline = ft_checkifnewline(buff);
	if (isnewline == 0)
	{
		ft_cleanbuff(buff, 0);
		return (0);
	}
	while (buff[i + isnewline] != '\0')
		i++;
	temp = malloc((sizeof(char) * i) + 1);
	temp[i] = '\0';
	ft_strlcpy(temp, &(buff[isnewline]), i);
	ft_cleanbuff(buff, 0);
	ft_strlcpy(buff, temp, i);
	free(temp);
	return (ft_checkifnewline(buff));
}

static	char	*ft_createnewstring(char *new, char *buff)
{
	size_t	i;

	i = ft_strlen(buff);
	if (i != 0)
	{
		new = malloc((sizeof(char) * i) + 1);
		new[i] = '\0';
	}
	new = ft_strlcpy(new, buff, i);
	ft_cleanbuff(buff, 0);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*new;
	ssize_t		i;
	size_t		linelen;

	new = NULL;
	linelen = ft_checkcurrentbuff(buff);
	if (linelen)
		return (ft_copynewline(buff, linelen));
	new = ft_createnewstring(new, buff);
	i = 1;
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == 0 && new != NULL)
			return (new);
		if (i <= 0)
			return (NULL);
		ft_cleanbuff(buff, i);
		new = ft_realloc(new, buff, i);
		if (ft_checkifnewline(new))
			return (new);
	}
	return (new);
}

int	main(void)
{
	size_t	i = 0;
	int	fd = open("test.txt", O_RDONLY);
	while (i < 2)
	{
		printf("%s", get_next_line(fd));
		//get_next_line(fd);
		i++;
	}
}
