/*
** my_env.c for my_env in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 01:49:58 2017 Nicolas
** Last update Fri Apr  7 06:21:22 2017 Nicolas
*/

#include "prototypes.h"

int	my_env(char **env)
{
  if (show_tab(env) == 84)
    return (my_putstr("Error in the Env.. too bad", 2, RED), 84);
  return (0);
}