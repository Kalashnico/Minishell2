/*
** my_exec_brut.c for my_exec_brut in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Tue Apr  4 05:03:20 2017 Nicolas
** Last update Sat Apr  8 23:03:52 2017 Nicolas
*/

#include "prototypes.h"

int	my_execve_brut(char *path, char **av, char **env, t_point *st_rt)
{
  if (find_if_exist(path) == 84)
    return (84);
  if ((st_rt->pid = fork()) == -1)
    return (84);
  if (wait_pid_exec(path, av, env, st_rt) == 84)
    return (84);
  return (0);
}
