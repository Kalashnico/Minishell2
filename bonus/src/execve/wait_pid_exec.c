/*
** wait_pid_exec.c for wait_pid_exec in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/execve
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Fri Apr  7 05:51:10 2017 Nicolas
** Last update Sat Apr  8 23:05:15 2017 Nicolas
*/

#include "prototypes.h"

int	wait_pid_exec(char *cmd, char **av, char **env, t_point *st_rt)
{
  int   status;

  if (st_rt->pid == 0)
    {
      if ((execve(cmd, av, env)) == -1)
	return (84);
    }
  else
    {
      if (wait(&status) == 84)
	return (84);
      signal_process(status, st_rt);
    }
  return (0);
}
