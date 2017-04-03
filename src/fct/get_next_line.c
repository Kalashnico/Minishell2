/*
** get_next_line.c for get_next_line in /home/guerin_n/Epitech/CPE/CPE_2016_getnextline
**
** Made by Nicolas Guerin
** Login   <guerin_n@epitech.net>
**
** Started on  Sun Jan 15 21:24:05 2017 Nicolas Guerin
** Last update Mon Feb 27 13:52:19 2017 Nicolas Guerin
*/

#include "prototypes.h"
#include "get_next_line.h"

char	*my_strdup_gnl(char *src)
{
  int	i;
  char	*str;
  int	ret;

  i = 0;
  if ((ret = check_n(src)) == -1)
    return (NULL);
  if ((str = malloc(sizeof(char) * ret + 1)) == NULL)
    return (NULL);
  while (i < ret)
    {
      str[i] = src[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}

int	check_n(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] == '\n')
	return (i);
      i++;
    }
  return (-1);
}

char	*boucle_gnl(char *line, char *buff, int ret, int i)
{
  my_strcat(line, buff);
  i = 0;
  while (buff[ret + 1] != '\0')
    {
      buff[i] = buff[ret + 1];
      i++;
      ret++;
    }
  buff[ret] = 0;
  while (i < READ_SIZE + 1)
    {
      buff[i] = '\0';
      i++;
    }
  return (line);
}

char	*boucle_else_gnl(char *line, char *buff, int ret, int fd)
{
  int	i;
  i = 0;
  line = my_strcpy(line, buff);
  while (i < READ_SIZE + 1)
    {
      buff[i] = '\0';
      i++;
    }
  if ((ret = read(fd, buff, READ_SIZE)) <= 0)
    return (NULL);
  return (line);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1] = {'\0'};
  char		*line;
  int		ret;
  int		i;
  int		tmp;

  i = 0;
  tmp = 0;
  line = NULL;
  if (!buff[0] && (ret = read(fd, buff, READ_SIZE)) <= 0)
   return (NULL);
  while (tmp++ != -1)
    {
      if ((line = my_realloc(line, (tmp * READ_SIZE))) == NULL)
	return (NULL);
      if ((ret = check_n(buff)) != -1)
	return (line = boucle_gnl(line, buff, ret, i), line);
      else
	{
	  if ((line = boucle_else_gnl(line, buff, ret, fd)) == NULL)
	    return (NULL);
	}
    }
  return (NULL);
}
