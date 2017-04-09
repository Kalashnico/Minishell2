/*
** my_cd_home_exec.c for my_cd_home_exec in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/builtin
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Fri Apr  7 05:58:31 2017 Nicolas
** Last update Sun Apr  9 02:51:25 2017 Nicolas
*/

#include "prototypes.h"

char	**cd_home_exec(char *cmd, char **env)
{
  if ((cmd = my_cd_home(env)) == NULL)
    return (NULL);
  if ((chdir(cmd)) == -1)
    return (my_putstr("Access denied : ", 2, RED), env);
  return (env);
}
