/*
** epur_str.c for epur sr in /home/nicolas/Epitech/Shell/PSU_2016_minishell2
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Wed Apr  5 02:29:00 2017 Nicolas
** Last update Sat Apr  8 16:22:31 2017 Nicolas
*/

#include "prototypes.h"

char	*epur_str(char *str)
{
  char	*src;
  int	i;
  int	j;

  i = (str[0] == ' ') ? 1 : 0;
  j = 0;
  if ((src = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
	    i = i + 1;
	  if (j > 0 && str[i] != '\0')
	    src[j++] = ' ';
	}
      src[j] = str[i];
      j = j + 1;
      i = i + 1;
    }
  src[j] = '\0';
  return (src);
}
