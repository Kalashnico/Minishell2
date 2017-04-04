/*
** epur_str.c for test in /home/nicolas/Epitech/Shell/PSU_2016_minishell2
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Mon Apr  3 18:56:16 2017 Nicolas
** Last update Mon Apr  3 19:14:02 2017 Nicolas
*/

#include "prototypes.h"

char	*epur_str(char *str)
{
  int	i;
  int	j;
  char	*new_str;

  if ((new_str = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str && str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while (str[i] == ' ' || str[i] == '\t' )
	    i++;
	  new_str[j] = ' ';
	  j++;
	}
      new_str[j] = str[i];
      j++;
      i++;
    }
  return (new_str);
}
