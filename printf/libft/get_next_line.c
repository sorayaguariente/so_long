/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguarien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:36:29 by sguarien          #+#    #+#             */
/*   Updated: 2022/12/01 14:36:08 by sguarien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Write a function that returns a line read from a file descriptor.
Files descriptors(fd) are a reference that points to a file 
that is open on the computer.
Returns a string of characters witch will be the line that 
was read from the file, You should be able to read the entire 
file on a loop on the same file. So on the first call it will
return the first line of the file and each time you call it again
on this file it will send the "next line" so line number 2,
line number 3 until there are no more. and if there is 
nothing more to read in the file, or if there is an error while 
this function is running, it will return NULL. And the external
functions that can use to code this function are read(), 
malloc() and free().
static variable cannot be accessed from other files */

#include "libft.h"

/*buffer_size are how many characters is going to be read at time on
read. Bytes is set to  1 so it can enter on the loop for the first 
time. while don't find \n and still have something to read
bytes = read because is still waiting the return of read
if bytes are -1 is because there is a error on read
array[bytes] = \0 to finalize buffer
str = ft_free_join to combine what was just read with the str
and return str to return str with more caracters*/
char	*ft_read(int fd, char *str)
{
	char	*array;
	int		count;

	array = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!array)
		return (NULL);
	count = 1;
	while (!ft_strchr_gnl(str, '\n') && count != 0)
	{
		count = read(fd, array, BUFFER_SIZE);
		if (count == -1)
		{
			free(str);
			free(array);
			return (NULL);
		}
		array[count] = '\0';
		str = ft_free_join(str, array);
	}
	free(array);
	return (str);
}

/*uses static char so it can remember where stoped the last time
//if fd is negative is because got a error, 
and the buffer to be <= 0 won't read
s = ft_read - the function will read the buffer and save 
the new str generated in s
line = ft_get line - is the line that is going to be used now
s = ft_new_line will store what is left of the read*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_read(fd, s);
	if (!s)
		return (NULL);
	line = ft_get_line(s);
	s = ft_new_line(s);
	return (line);
}

/*#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	fd = open("files/test.txt", O_RDONLY);
	prt = get_next_line(fd);
	printf("\nFunc Return: %s\n", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\nFunc Return: %s\n", prt);
	free(prt);
	prt = get_next_line(fd);
	printf("\nFunc Return: %s\n", prt);
	free(prt);
	close(fd);
}*/
/*#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	int		i = 0;
	fd = open("files/1-brouette.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	while (i < 80)
	{
		prt = get_next_line(fd);
		printf("%s", prt);
		free(prt);
		i++;
	}
	close(fd);
}*/
/*#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*prt;
	int		i = 0;
	fd = open("files/42_no_nl", O_RDONLY);
	printf("fd = %d\n", fd);
	while (i < 1)
	{
		prt = get_next_line(fd);
		printf("%s", prt);
		free(prt);
		i++;
	}
	close(fd);
}*/
