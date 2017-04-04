/*
** epur_str.c for epur_str in /home/nicolas/Epitech/Shell/PSU_2016_minishell2
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Tue Apr  4 03:41:40 2017 Nicolas
** Last update Tue Apr  4 04:32:43 2017 Nicolas
*/

#include "prototypes.h"

static int	my_strlen_spe(char *str)
{
  int	i;
  int	res;

  res = 0;
  i = 0;
  while (str && str[i])
    {
      if (str[i] > 32)
	res++;
      i++;
    }
  return (res);
}

int	count_space(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] <= 32)
	return (1);
      i++;
    }
  return (0);
}

char	*epur_str(char *str)
{
  char	*new_str;
  int	i;
  int	j;

  if ((i = count_space(str)) == 0)
    return (str);
  i = my_strlen_spe(str);
  if ((new_str = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str && str[i])
    {
      if (str[i] > 32)
	{
 	  if (str[i - 1] == ' ')
	    {
	      new_str[j] = ' ';
	      j++;
	    }
	  new_str[j] = str[i];
	  j++;
	}
      i++;
    }
  new_str[j] = '\0';
  return (new_str);
}
