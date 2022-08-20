/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:01:23 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/19 14:30:11 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

#include <stdio.h>

static int	ft_strlen(char *str);
static char	*ft_strjoin(char *str1, char *str2);
static int	is_nl(char *str);
static char	*read_buff(int fd, char *buff);
static char	*catch_line(char *buff);
static char	*next_round(char *buff);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;

	if (fd < 0 || BS <= 0)
		return (NULL);
	buff = read_buff(fd, buff);
	if (!buff)
		return (NULL);
	line = catch_line(buff);
	// if (!line)
	// 	return (NULL);
	buff = next_round(buff);
	// if (!buff)
		// return (NULL);
	return (line);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char *str1, char *str2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	while (str1 && str1[i])
		str[k++] = str1[i++];
	j = 0;
	while (str2[j])
		str[k++] = str2[j++];
	str[k] = '\0';
	free(str1);
	return (str);
}

static int	is_nl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

//! ////////// ////////////////////   ///////////////////// ///////////
static char	*read_buff(int fd, char *buff)
{
	char	*tmp;
	int		rs;

	tmp = malloc(BS + 1);
	if (!tmp)
		return (NULL);
	rs = 1;
	while (!is_nl(buff) && rs)
	{
		rs = read(fd, tmp, BS);
		if (rs == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[rs] = '\0';
		buff = ft_strjoin(buff, tmp);
		if (!buff)
			return (NULL);
	}
	// printf("%s[read_buff]\tbuff = %s%s\n",RED, buff, NC);
	free(tmp);
	return (buff);
}

//! ////////// ////////////////////   ///////////////////// ///////////
static char	*catch_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	// printf("%s[catch_line]\tline = %s%s\n",BLU, line, NC);
	return (line);
}

//! ////////// ////////////////////   ///////////////////// ///////////
static char	*next_round(char *buff)
{
	char	*next;
	int		i;
	int		j;

	if (!is_nl(buff))
	{
		free(buff);
		return (NULL);
	}
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	next = malloc(ft_strlen(buff) - i + 1);
	i++;
	if (!next)
		return (NULL);
	j = 0;
	while (buff[i])
		next[j++] = buff[i++];
	next[j] = '\0';
	free(buff);
	return (next);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// #include <stdio.h>

// int	main()
// {
// 	char	*str1 = "hello world";
// 	char	*str2 = "here it is\nand here";

// 	printf("%d\t%d\n", is_nl(str1), is_nl(str2));
// 	return (0);
// }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
