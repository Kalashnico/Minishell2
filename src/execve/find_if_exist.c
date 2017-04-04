/*
** find_if_exist.c for find_if_exist in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Wed Apr  5 00:11:05 2017 Nicolas
** Last update Wed Apr  5 01:22:15 2017 Nicolas
*/

#include "prototypes.h"

int	find_if_exist(char *cmd)
{
  if ((access(cmd, F_OK)) != -1)
    return (0);
  return (84);
}
