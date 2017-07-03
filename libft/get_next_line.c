/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kialvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:42:47 by kialvare          #+#    #+#             */
/*   Updated: 2016/11/14 21:44:20 by kialvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int  line_read(int const fd, char *buff, char **store)
{
    char    *tmp;
    char    *check;
    int     i;

    i = 0;
    while (!(check = ft_strchr(*store, '\n')) &&
        (i = read(fd, buff, BUFF_SIZE)) > 0)
    {
        tmp = *store;
        *store = ft_strjoin(tmp, buff);
        free(tmp);
        ft_bzero(buff, BUFF_SIZE + 1);
    }
    if (i == -1)
        return (-1);
    if (i == 0 && !check)
        return (0);
    return (1);
}

int         get_next_line(int const fd, char **line)
{
    static char *store[4000];
	char		*buff;
    char		*tmp;
    int			ret;

	buff = ft_strnew(BUFF_SIZE);
    if (fd < 0 || line == NULL || read(fd, *line, 0) < 0)
        return (-1);
    if (store[fd] == NULL)
        store[fd] = ft_strnew(1);
    ret = line_read(fd, buff, &(store[fd]));
    if (ret == 0)
    {
        *line = store[fd];
        store[fd] = NULL;
		if (*line && **line)
			return (1);
		else
			return (0);
    }
    *line = ft_strsub(store[fd], 0, ft_strchr(store[fd], '\n') - store[fd]);
    tmp = store[fd];
    store[fd] = ft_strdup(ft_strchr(store[fd], '\n') + 1);
    free(tmp);
    return (1);
}

