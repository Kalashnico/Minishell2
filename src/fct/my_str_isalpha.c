/*
** my_str_isalpha.c for my_str_isalpha in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/fct
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  9 02:15:29 2017 Nicolas
** Last update Sun Apr  9 02:22:49 2017 Nicolas
*/

#include "prototypes.h"

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
	return (84);
      i++;
    }
  return (0);
}
