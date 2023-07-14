/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguarien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:48:40 by sguarien          #+#    #+#             */
/*   Updated: 2022/12/01 12:54:00 by sguarien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*calculate the size of the array*/
size_t	ft_strlen_gnl(const char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

/*find the first ocorrence of a character*/
char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen_gnl(s)]);
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

/*Get the strings together*/
char	*ft_free_join(char *s, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
	{
		s = (char *)malloc(1 * sizeof(char));
		s[0] = '\0';
	}
	if (!s || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen_gnl(s)
					+ ft_strlen_gnl(buffer)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s)
		while (s[++i] != '\0')
			str[i] = s[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen_gnl(s) + ft_strlen_gnl(buffer)] = '\0';
	free(s);
	return (str);
}

/* gets the line that is going to be used, if s[i] is empty, returns null,
while the string do not end (in \n) allocate the size of the line untill
the first newline. after i is going to be 0 so it can start write again
and in the line that you are, untill the end start to put the str in s
after that include a newline on str and return that line*/
char	*ft_get_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*gets the rest of the last time that get_next_line were called
first see ud s exists, if not, clean pointer using free and return null
use str to alocate space that something on s, save the str, end it with null
and then clean because it is stored at str.*/
char	*ft_new_line(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen_gnl(s) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}
