/*
** count_colums.c for countçcolum in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/fct
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sat Apr  8 15:28:31 2017 Nicolas
** Last update Sat Apr  8 15:29:28 2017 Nicolas
*/

#include "prototypes.h"

int	count_colum(char *buff)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (buff && buff[i])
    {
      if (buff[i] == ';')
	res++;
      i++;
    }
  return (res);
}
