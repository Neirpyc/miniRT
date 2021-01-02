/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugier <caugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:52:15 by caugier           #+#    #+#             */
/*   Updated: 2021/01/01 15:52:12 by caugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_int.h"
#include "../libft/libft.h"
#include "../gc_malloc/gc_malloc.h"
#include <unistd.h>

t_location	*gen_loc(t_location *loc, size_t char_beg, size_t word_beg,
	size_t word_end)
{
	loc->char_beg = char_beg;
	loc->arg_end = word_end;
	loc->arg_begin = word_beg;
	return (loc);
}

static ssize_t	write_std(char *line)
{
	ssize_t	len;

	len = ft_strlen(line);
	line[len] = '\n';
	write(STDOUT_FILENO, line, len + 1);
	return (len);
}

void	highlight_words(char *line, ssize_t c_beg,
	size_t w_beg, size_t w_end)
{
	ssize_t	len;
	ssize_t	i;
	size_t	wd;

	len = write_std(line);
	i = 0;
	wd = 0;
	while (i < len)
	{
		if (i == c_beg)
			line[i] = '^';
		if (!ft_isspace(line[i]))
		{
			if ((wd == w_beg && i > c_beg)
				|| (wd >= w_beg && wd <= w_end && i != c_beg))
				line[i] = '~';
			else if (i != c_beg)
				line[i] = ' ';
			if (ft_isspace(line[i + 1]) && i + 1 != c_beg)
				wd++;
		}
		i++;
	}
	write(STDOUT_FILENO, line, len + 1);
	line[len] = '\0';
}

void	err_line(char *line, t_location *loc, int errcode)
{
	if (errcode == 0)
		return ;
	ft_put_strerror(errcode);
	write(STDOUT_FILENO, "Note: error at line ", 20);
	ft_putnbr_fd(loc->line + 1, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	highlight_words(line, loc->char_beg, loc->arg_begin, loc->arg_end);
	gc_exit(-1);
}

void	err_dup_line(t_list *lines, size_t prev_line,
	size_t curr_line, int errcode)
{
	size_t	len;
	size_t	lst_size;

	ft_put_strerror(errcode);
	write(STDOUT_FILENO, "Note: redefined at line ", 24);
	ft_putnbr_fd((int)curr_line + 1, STDOUT_FILENO);
	write(STDOUT_FILENO, "\nNote: previous declaration at line ", 36);
	ft_putnbr_fd((int)prev_line + 1, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	lst_size = list_size(lines) - 1;
	while (prev_line != lst_size)
	{
		lst_size--;
		lines = lines->next;
	}
	len = ft_strlen(lines->content);
	((char *)lines->content)[len] = '\n';
	write(STDOUT_FILENO, lines->content, len + 1);
	if (len > 0)
	{
		((char *)lines->content)[0] = '^';
		ft_memset(&((char *)lines->content)[1], '~', len - 1);
	}
	write(STDOUT_FILENO, lines->content, len + 1);
	gc_exit(-1);
}
