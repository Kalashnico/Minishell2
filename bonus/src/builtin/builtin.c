/*
** builtin.c for builtin in /home/nicolas/Epitech/Shell/PSU_2016_minishell1/src/builtin
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Sun Apr  2 18:35:03 2017 Nicolas
** Last update Sun Apr  9 02:28:07 2017 Nicolas
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
  if (my_memcmp("env", buff, 4) == 0)
    if (my_env(env) == 84)
      return (84);
  return (0);
}

char	**builtin_env(char *buff, char **env, t_point *st_rt)
{
  char	**tab;
  int	i;

  i = my_strlen_tab(env);
  if ((tab = my_str_to_wordtab(buff, ' ')) == NULL)
    return (NULL);
  if (my_memcmp("cd ", buff, 3) == 0)
    if (my_cd(env, tab, buff, st_rt) == NULL)
      return (NULL);
  if (my_memcmp("setenv", buff, 6) == 0)
    if ((env = my_setenv(env, buff, i)) == NULL)
      return (NULL);
  if (my_memcmp("unsetenv", buff, 8) == 0)
    if ((env = my_unsetenv(env, buff)) == NULL)
      return (NULL);
  return (env);
}
