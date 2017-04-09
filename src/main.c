/*
** main.c for main in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  9 23:17:50 2017 Nicolas
** Last update Sun Apr  9 23:17:52 2017 Nicolas
*/

#include "prototypes.h"

void	prompt()
{
  my_putstr("$>", 0);
}

char	**mysh(char **env, char *buff, char **new_av, t_point *st_rt)
{
  if (check_if_built_exist(buff) == 0)
    {
      if ((builtin(buff, env)) == 84 ||
	  (env = builtin_env(buff, env, st_rt)) == NULL)
	my_putstr("Error in the execution of the command\n", 2);
    }
  else
    {
      if ((my_execve_brut(buff, new_av, env, st_rt)) == 84)
	if (my_execve(new_av, env, st_rt) == 84 && my_strlen(buff) != 0)
	  {
	    my_putstr(new_av[0], 2);
	    my_putstr(": Command not found.\n", 2);
	   st_rt->ret = 1;
	  }
    }
  free_tab(new_av);
  return (env);
}

int	init_shell(int ac)
{
  if (ac != 1)
    return (84);
  prompt();
  if (signal(SIGINT, &get_sigint) == SIG_ERR)
    my_putstr("ERROR_SIGNAL\n", 2);
  return (0);
}

char	**shell_loop(char **env, char **new_tab, t_point *st_rt)
{
  char	**new_av;
  int	i;

  i = 0;
  while (new_tab && new_tab[i])
    {
      if ((new_tab[i] = epur_str(new_tab[i])) == NULL ||
	  (new_av = my_str_to_wordtab(new_tab[i], ' ')) == NULL)
	return (NULL);
      if ((my_strcmp("exit", new_av[0]) == 0))
	exit(my_getnbr(new_av[1]));
      if ((env = mysh(env, new_tab[i], new_av, st_rt)) == NULL)
	return (NULL);
      i++;
    }
  return (env);
}

int		main(int ac, __attribute__ ((unused)) char **av, char **env)
{
  char		*buff;
  char		**new_tab;
  char		**new_env;
  t_point	st_rt;

  if ((init_shell(ac)) == 84)
    return (my_putstr("Too many arguments !\n", 2), 84);
  if ((new_env = copy_tab(env)) == NULL)
    return (84);
  st_rt.ret = 0;
  while ((buff = get_next_line(0)) != NULL)
    {
      if (count_pipe(buff) < 2)
	{
	  if ((new_tab = my_str_to_wordtab(buff, ';')) == NULL)
	    return (84);
	  if ((new_env = shell_loop(new_env, new_tab, &st_rt)) == NULL)
	    return (84);
	  prompt();
	}
      else
	prompt();
    }
  return (st_rt.ret);
}
