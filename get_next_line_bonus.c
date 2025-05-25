/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:23:29 by dbriant           #+#    #+#             */
/*   Updated: 2025/05/09 15:31:40 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*ft_createline(char *buff)
{
	size_t	strlen;
	size_t	newlineposition;
	char	*new;

	if (buff == NULL)
		return (NULL);
	strlen = ft_strlen(buff);
	newlineposition = ((char *)ft_memchr(buff, '\n', strlen) - buff) + 1;
	new = ft_calloc(newlineposition + 1, sizeof(char));
	ft_strlcpy(new, buff, newlineposition + 1);
	return (new);
}

static	char	*ft_checkcurrentbuff(char *buff, size_t buffsize)
{
	char	*new;
	char	*old;
	size_t	i;

	i = 0;
	old = ft_memchr(buff, '\n', buffsize);
	if (buff == NULL)
		return (NULL);
	if (old == NULL)
	{
		free(buff);
		return (NULL);
	}
	old = old + sizeof(char);
	while (old[i] != '\0')
		i++;
	new = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(new, old, i + 1);
	free(buff);
	return (new);
}

static	char	*ft_addstring(char *buff, char *str, size_t arrlen)
{
	char	*new;
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	new = ft_calloc(arrlen + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, str, ft_strlen(str) + 1);
	free(str);
	ft_strlcat(new, buff, arrlen + 1);
	while (new[i] != '\0')
	{
		if (new[i++] == '\n')
			break ;
	}
	new[i] = '\0';
	return (new);
}

static	char	*ft_readfd(char *buff, char **newbuff, int fd, size_t buffsize)
{
	char	*new;
	ssize_t	byte_readed;
	size_t	strlen;

	strlen = ft_strlen(buff);
	new = ft_calloc(strlen + 1, sizeof(char));
	ft_strlcpy(new, buff, strlen + 1);
	free(buff);
	*newbuff = ft_calloc(buffsize + 1, sizeof(char));
	byte_readed = read(fd, *newbuff, buffsize);
	while (byte_readed > 0)
	{
		strlen = strlen + byte_readed;
		(*newbuff)[byte_readed] = '\0';
		new = ft_addstring(*newbuff, new, strlen);
		if (new[ft_strlen(new) - 1] == '\n')
			return (new);
		byte_readed = read(fd, *newbuff, buffsize);
		if (byte_readed == 0)
			return (new);
	}
	if (ft_strlen(new) != 0)
		return (new);
	free(new);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*arr[4096];
	char		*new;

	if ((fd < 0 || fd > 4096) || (BUFFER_SIZE < 1))
		return (NULL);
	arr[fd] = ft_checkcurrentbuff(arr[fd], BUFFER_SIZE);
	if (ft_memchr(arr[fd], '\n', BUFFER_SIZE) != NULL)
		return (ft_createline(arr[fd]));
	new = ft_readfd(arr[fd], &arr[fd], fd, BUFFER_SIZE);
	if (*arr[fd] == '\0')
	{
		free(arr[fd]);
		arr[fd] = NULL;
	}
	if (new != NULL)
		return (new);
	free(new);
	return (NULL);
}
/*
int	main(void)
{
	int		fd_one;
	int		fd_two;
	char	*t;
	char	*p;

	fd_one = open("test_one.txt", O_RDONLY);
	fd_two = open("test_two.txt", O_RDONLY);
	printf("Return: %s", t = get_next_line(fd_one));
	//printf("Return: %s", p = get_next_line(fd_two));
	free(t);
	//free(p);
	printf("Return: %s", t = get_next_line(fd_one));
	//printf("Return: %s", p = get_next_line(fd_two));
	free(t);
	//free(p);
		printf("Return: %s", t = get_next_line(fd_one));
	//printf("Return: %s", p = get_next_line(fd_two));
	free(t);
		printf("Return: %s", t = get_next_line(fd_one));
	//printf("Return: %s", p = get_next_line(fd_two));
	free(t);
	printf("Return: %s", t = get_next_line(fd_one));
	//printf("Return: %s", p = get_next_line(fd_two));
	free(t);
}
*/