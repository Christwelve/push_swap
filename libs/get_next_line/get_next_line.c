/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:13:38 by cmeng             #+#    #+#             */
/*   Updated: 2023/01/29 22:13:38 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cut_buffer(char *t_buf);
char	*ft_cut_output(char *t_buf);
int		ft_newline(char *t_buf);

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*t_buf = NULL;
	char			*out;
	int				s_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_calloc((BUFFER_SIZE), sizeof(char));
	if (buf == NULL)
		return (NULL);
	s_read = 1;
	while (!ft_newline(t_buf) && s_read != 0)
	{
		s_read = read(fd, buf, BUFFER_SIZE);
		if (s_read == -1)
			return (free(t_buf), free(buf), t_buf = NULL, NULL);
		t_buf = ft_strjoin_new(t_buf, buf, s_read);
	}
	free(buf);
	out = ft_cut_output(t_buf);
	t_buf = ft_cut_buffer(t_buf);
	return (out);
}

char	*ft_cut_buffer(char *t_buf)
{
	int		i;
	char	*out;

	i = 0;
	if (t_buf == NULL)
		return (NULL);
	if (t_buf[0] == '\0')
		return (free(t_buf), NULL);
	while (t_buf[i] != '\n' && t_buf[i] != '\0')
		i++;
	out = ft_substr_new(t_buf, i + 1, ft_strlen(t_buf) - (i));
	return (free(t_buf), out);
}

char	*ft_cut_output(char *t_buf)
{
	int		i;
	char	*out;

	i = 0;
	if (t_buf == NULL)
		return (NULL);
	if (t_buf[i] == '\0')
		return (NULL);
	while (t_buf[i] != '\n' && t_buf[i] != '\0')
		i++;
	out = ft_substr_new(t_buf, 0, i + 1);
	if (out == NULL)
		return (NULL);
	return (out);
}

int	ft_newline(char *t_buf)
{
	if (t_buf == NULL)
		return (0);
	while (*t_buf != '\0')
	{
		if (*t_buf == '\n')
			return (1);
		t_buf++;
	}
	return (0);
}
