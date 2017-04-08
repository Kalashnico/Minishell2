/*
** main.c for main in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 06:15:14 2017 Nicolas
** Last update Sat Apr  8 21:53:28 2017 Nicolas
*/

#include "prototypes.h"

void	prompt()
{
  my_putstr("$>", 0);
}

char	**mysh(char **env, char *buff, char **new_av, int *ret)
{
  if (check_if_built_exist(buff) == 0)
    {
      if ((builtin(buff, env)) == 84 ||
	  (env = builtin_env(buff, env, ret)) == NULL)
	my_putstr("Error in the execution of the command\n", 2);
    }
  else
    {
      if ((my_execve_brut(buff, new_av, env)) == 84)
	if (my_execve(new_av, env) == 84 && my_strlen(buff) != 0)
	  {
	    my_putstr(new_av[0], 2);
	    my_putstr(": Command not found.\n", 2);
	   *ret = 1;
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

char	**shell_loop(char **env, char **new_tab, int *ret)
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
      if ((env = mysh(env, new_tab[i], new_av, ret)) == NULL)
	return (NULL);
      i++;
    }
  return (env);
}

int	main(int ac,__attribute__ ((unused)) char **av, char **env)
{
  char	*buff;
  char	**new_tab;
  int	ret;

  if ((init_shell(ac)) == 84)
    return (my_putstr("Too many arguments !\n", 2), 84);
  ret = 0;
  while ((buff = get_next_line(0)) != NULL)
    {
      if ((new_tab = my_str_to_wordtab(buff, ';')) == NULL)
	return (84);
      if ((env = shell_loop(env, new_tab, &ret)) == NULL)
	return (84);
      prompt();
    }
  return (ret);
}
