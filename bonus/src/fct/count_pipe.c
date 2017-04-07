/*
** count_pipe.c for count_pipie in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/fct
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Thu Apr  6 23:51:59 2017 Nicolas
** Last update Fri Apr  7 02:16:04 2017 Nicolas
*/

#include "prototypes.h"

int	count_pipe(char *buff)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (buff && buff[i])
    {
      if (buff[i] == '|')
	res++;
      i++;
    }
  return (res);
}
