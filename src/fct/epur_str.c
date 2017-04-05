/*
** epur_str.c for epur sr in /home/nicolas/Epitech/Shell/PSU_2016_minishell2
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Wed Apr  5 02:29:00 2017 Nicolas
** Last update Wed Apr  5 02:33:37 2017 Nicolas
*/

#include "prototypes.h"

char	*epur_str(char *str)
{
  char	*src;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((src = malloc(sizeof(char *) * my_strlen(str))) == NULL)
    return (NULL);
  while (str[i] != '\0')
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
