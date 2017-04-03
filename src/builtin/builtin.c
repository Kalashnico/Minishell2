/*
** builtin.c for builtin in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src/builtin
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 18:35:03 2017 Nicolas
** Last update Mon Apr  3 14:19:23 2017 Nicolas
*/

#include "prototypes.h"

int	check_if_built_exist(char *buff)
{
  if ((my_memcmp("cd ", buff, 3) != 0) &&
      (my_memcmp("env", buff, 3) != 0) &&
      (my_memcmp("setenv", buff, 6) != 0) &&
      (my_memcmp("unsetenv", buff, 8) != 0))
    return (-1);
  return (0);
}

int	builtin(char *buff, char **env)
{
  if (check_if_built_exist(buff) == -1)
    return (-1);
  if (my_memcmp("cd ", buff, 3) == 0)
    if (my_cd(buff) == 84)
      return (84);
  if (my_memcmp("env", buff, 4) == 0)
    if (my_env(env) == 84)
      return (84);
  return (0);
}
