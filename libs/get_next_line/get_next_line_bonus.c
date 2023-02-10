/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:36:52 by cmeng             #+#    #+#             */
/*   Updated: 2023/01/29 22:15:34 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_cut_buffer(char *t_buf);
char	*ft_cut_output(char *t_buf);
int		ft_newline(char *t_buf);

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*t_buf[1024] = {NULL};
	char			*out;
	int				s_read;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_calloc((BUFFER_SIZE), sizeof(char));
	if (buf == NULL)
		return (NULL);
	s_read = 1;
	while (!ft_newline(t_buf[fd]) && s_read != 0)
	{
		s_read = read(fd, buf, BUFFER_SIZE);
		if (s_read == -1)
			return (free(buf), free(t_buf[fd]), t_buf[fd] = NULL, NULL);
		t_buf[fd] = ft_strjoin_new(t_buf[fd], buf, s_read);
	}
	free(buf);
	out = ft_cut_output(t_buf[fd]);
	t_buf[fd] = ft_cut_buffer(t_buf[fd]);
	return (out);
}

char	*ft_cut_buffer(char *t_buf)
{
	int		i;
	char	*out;

	i = 0;
	if (t_buf == NULL)
		return (NULL);
	if (t_buf[i] == '\0')
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
