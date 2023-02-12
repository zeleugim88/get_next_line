/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiguele <dmiguele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:53:00 by dmiguele          #+#    #+#             */
/*   Updated: 2023/02/11 13:53:04 by dmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//ft_read function reads from the file descriptor.
//and concatenates the new data to the existing content until it finds a newline 
//character or reaches the end of the file.
char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}
/*
This is a function that reads a line from a file descriptor and returns it as a string. 
The line is defined as a sequence of characters ending with a newline character ('\n') 
or the end of the file (EOF).*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
//The function first checks if the file descriptor passed as an argument is valid 
//(i.e., it is not negative or the buffer size is not set to 0).
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
/*it calls the ft_read function to read from the file descriptor and store the 
content in the static variable str.*/
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_next_str(str);
	return (line);
}
/*
int	main(void)
{
	int fd;
	char *tab;

	fd = open("text.txt", O_RDONLY);
	tab = get_next_line(fd);
	printf("%s", tab);
	free(tab);
	tab = get_next_line(fd);
	printf("%s", tab);
	tab = get_next_line(fd);
	printf("%s", tab);
	tab = get_next_line(fd);
	printf("%s", tab);
	close(fd);
	return (0);
}
*/
