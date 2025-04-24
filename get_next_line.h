/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbriant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:18:29 by dbriant           #+#    #+#             */
/*   Updated: 2025/04/07 21:18:50 by dbriant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <sys/types.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1028
# endif

char	*get_next_line(int fd);
char	*ft_copynewline(char *buff, size_t len);
size_t	ft_strlen(char *str);
char	*ft_strlcpy(char *dest, char *src, size_t len);
char	*ft_realloc(char *new, char *buff, ssize_t len);
size_t	ft_checkifnewline(char *buff);
void	ft_cleanbuff(char *buff, size_t size);

#endif