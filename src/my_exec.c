/*
** my_exec.c for my_execv in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 17:05:58 2017 Nicolas
** Last update Sun Apr  2 19:24:09 2017 Nicolas
*/

#include "prototypes.h"

int	check_path(char **env)
{
  int   i;

  i = 0;
  while (env && env[i] != NULL)
    {
      if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
	  && env[i][3] == 'H' && env[i][4] == '=')
	return (i);
      i++;
    }
  return (i);
}

char	*change_path(char *env)
{
  char  *new_env;
  int   i;
  int   a;

  a = 0;
  i = 5;
  if ((new_env = malloc(sizeof(char) * (my_strlen(env) - 4))) == NULL)
    return (NULL);
  while (env && env[i] != '\0')
    {
      new_env[a] = env[i];
      a++;
      i++;
    }
  new_env[a] = '\0';
  return (new_env);
}

char	**get_new_path(char **env, char *buff)
{
  char	*env_rt;
  char	**tab;
  int	i;
  int	x;

  x = 0;
  i = check_path(env);
  env_rt = change_path(env[i]);
  tab = my_str_to_wordtab(env_rt, ':');
  while (tab && tab[x])
    {
      if ((tab[x] = my_realloc(tab[x], my_strlen(buff) + 2)) == NULL)
	return (NULL);
      my_strcat(tab[x], "/");
      my_strcat(tab[x], buff);
      x++;
    }
  return (tab);
}

char	*find_good_cmd(char **path)
{
  char	*cmd;
  int	i;

  i = 0;
  while (path && path[i])
    {
      cmd = my_strdup(path[i]);
      if ((access(cmd, F_OK)) != -1)
	return (cmd);
      i++;
    }
  return (NULL);
}

int	my_execve(char **av, char **env)
{
  char	**tab;
  char	*cmd;
  pid_t	pid;
  int	status;

  if ((tab = get_new_path(env, av[0])) == NULL ||
      (cmd = find_good_cmd(tab)) == NULL ||
      (pid = fork()) == -1)
    return (84);
  if (pid == 0)
    if ((execve(cmd, av, env)) == -1)
      return (84);
  wait(&status);
  return (0);
}
