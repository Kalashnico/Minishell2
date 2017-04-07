/*
** my_strlen_tab.c for my_strlen_tab in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/fct
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Wed Apr  5 00:17:27 2017 Nicolas
** Last update Wed Apr  5 01:20:53 2017 Nicolas
*/

#include "prototypes.h"

int	my_strlen_tab(char **env)
{
  int   i;

  i = 0;
  while (env && env[i])
    i++;
  return (i);
}
