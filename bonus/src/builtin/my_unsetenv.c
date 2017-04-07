/*
** my_unsetenv.c for my_unsetenv in /home/nicolas/Epitech/Shell/PSU_2016_minishell2/src/builtin
** 
** Made by Nicolas
** Login   <nicolas.guerin@epitech.eu>
** 
** Started on  Mon Apr  3 17:46:40 2017 Nicolas
** Last update Wed Apr  5 04:05:48 2017 Nicolas
*/

#include "prototypes.h"

int	find_name(char **env, char *str)
{
  int	i;

  i = 0;
  while (env && env[i])
    {
      if (my_memcmp(env[i], str, my_strlen(str)) == 0)
	return (i);
      i++;
    }
  return (0);
}

char	**my_unsetenv(char **env, char *buff)
{
  char	**tab;
  int	i;

  if ((tab = my_str_to_wordtab(buff, ' ')) == NULL)
    return (NULL);
  i = find_name(env, tab[1]);
  while (env && env[i])
    {
      env[i] = env[i + 1];
      i++;
    }
  free(env[i]);
  return (env);
}
