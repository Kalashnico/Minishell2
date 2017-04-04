/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/guerin_n
** 
** Made by Nicolas Guerin
** Login   <guerin_n@epitech.net>
** 
** Started on  Thu Jan 26 17:17:46 2017 Nicolas Guerin
** Last update Tue Apr  4 06:58:02 2017 Nicolas
*/

#include "prototypes.h"

static int	my_strlen_spe(char *str, char c)
{
  int		i;

  i = 0;
  while (str[i] && str[i] != c)
    i++;
  return (i);
}

static char	*my_strdup_spe(char *str, char c)
{
  int	i;
  char	*new_str;

  i = 0;
  if ((new_str = malloc(sizeof(char) * my_strlen_spe(str, c) + 1)) == NULL)
    return (NULL);
  while (str && str[i] && str[i] != c)
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}

static int	size_tab(char *str, char c)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == c)
	res = res + 1;
      i++;
    }
  res++;
  return (res);
}

char	**my_str_to_wordtab(char *str, char c)
{
  char	**tab;
  int	i;
  int	n;

  i = 0;
  n = 0;
  if ((tab = malloc(sizeof(char *) * (size_tab(str, c) + 2))) == NULL)
    return (NULL);
  while (str && str[i] != '\0')
    {
      if ((tab[n] = my_strdup_spe(&str[i], c)) == NULL)
	return (NULL);
      while (str[i] && str[i] != c)
	i++;
      if (str && str[i])
	i++;
      n++;
    }
  tab[n] = NULL;
  return (tab);
}
