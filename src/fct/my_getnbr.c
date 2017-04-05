/*
** my_getnbr.c for my_getnbr in /home/nicolas/Epitech/Shell/PSU_2016_minishell2
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Wed Apr  5 20:41:11 2017 Nicolas
** Last update Wed Apr  5 20:41:24 2017 Nicolas
*/

#include "prototypes.h"

int	my_getnbr(char *str)
{
  long  a;
  int   n;

  n = 0;
  a = 0;
  while (str[n] != '\0')
    {
      a = a * 10 + str[n] - 48;
      n = n + 1;
    }
  return (a);
}
