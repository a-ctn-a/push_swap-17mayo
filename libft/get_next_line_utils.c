/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzarago <anzarago@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:02:06 by anzarago          #+#    #+#             */
/*   Updated: 2025/01/27 18:20:30 by anzarago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = '\0';
	free (s1);
	return (dest);
}

char	*ft_alloc(char *str, int fd)
{
	char	*buffer;
	ssize_t	len;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	len = 1;
	while (!(ft_strchr(str, '\n')) && len > 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free (buffer);
			free (str);
			return (NULL);
		}
		buffer[len] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*ft_new_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (str[i] == 0)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	line = (char *) malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_remove_line(char *str)
{
	int		i;
	int		count;
	char	*nstr;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	nstr = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!nstr)
		return (NULL);
	i++;
	count = 0;
	while (str[i])
		nstr[count++] = str[i++];
	nstr[count] = '\0';
	free (str);
	return (nstr);
}
