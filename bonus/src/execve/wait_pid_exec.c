/*
** wait_pid_exec.c for wait_pid_exec in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/execve
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Fri Apr  7 05:51:10 2017 Nicolas
** Last update Fri Apr  7 05:51:26 2017 Nicolas
*/

#include "prototypes.h"

int	wait_pid_exec(char *cmd, char **av, char **env, pid_t pid)
{
  int   status;

  if (pid == 0)
    {
      if ((execve(cmd, av, env)) == -1)
	return (84);
    }
  else
    {
      if (wait(&status) == 84)
	return (84);
      signal_process(status);
    }
  return (0);
}
