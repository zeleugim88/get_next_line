/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiguele <dmiguele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:49:58 by dmiguele          #+#    #+#             */
/*   Updated: 2023/02/11 13:50:47 by dmiguele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
strchr function in C, which searches for the first occurrence of the character c in the string s. 
The function returns a pointer to the first occurrence of the character c in the string s. 
If the character is not found, the function returns a null pointer. 
If the input string s is a null pointer, the function returns a null pointer as well.
*/
char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]); //if it is not casted, does it not work?
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
/*
The string pointer is casted to (char *) because it's being returned as a pointer to a character, 
and the function definition specifies the return type as char *. 
The casting ensures that the pointer's type matches the expected return type. 
It is a way to tell the compiler that the data type of the pointer has changed, in this case from char * to char.
*/

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
/*
ft_line is a function that takes a string str as an argument and returns 
a new string that contains the characters from str up to but not including 
the first newline character ('\n'). If the input string str does not contain a 
newline character, the function returns a copy of the entire str. 
If the allocation of the new string fails, the function returns NULL.
*/
char	*ft_line(char *str)
{
	int		i;
	char	*tab;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	tab = (char *)malloc(sizeof(char) * (i + 2)); //por que 2?
	if (!tab)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tab[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab); //el string seria woifwlk\n\0 --> con salto de linea al final?
}

char	*ft_next_str(char *str)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++; //finds the position of \n
	if (!str[i]) //???? If the newline character is not found, it frees the input string and returns NULL.
	{//si se encontro \n antes, por que ahora no se ecuentra??
		free(str);
		return (NULL);
	}//it allocates a new string of size equal to the length of the input string 
	//minus the length of the string up to the newline character, plus one for the null terminator.
	tab = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!tab)
		return (NULL);
	i++;
	j = 0;
	while (str[i]) //It then copies the remaining part of the input string 
	//(after the newline character) into the new string. 
		tab[j++] = str[i++];
	tab[j] = '\0';
	//Finally, it frees the input string and returns a pointer to the newly allocated string.
	free(str);
	return (tab);
}
