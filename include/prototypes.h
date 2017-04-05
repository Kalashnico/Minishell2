/*
** prototypes.h for prototypes in /home/guerin_n/Epitech/Shell/PSU_2016_minishell1
** 
** Made by Nicolas Guerin
** Login   <guerin_n@epitech.net>
** 
** Started on  Mon Jan  9 15:46:26 2017 Nicolas Guerin
** Last update Wed Apr  5 02:32:35 2017 Nicolas
*/

#ifndef PROTOTYPES_H_
# define PROTOTYPES_H_

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>


/* ---  FCT --- */

void	my_putchar(char c, int fd);
void	my_putstr(char *str, int fd);
void	my_strcat(char *s1, char *s2);
void	free_tab(char **av);
int	my_strlen(char *str);
int	my_strncmp(char *s1, char *s2, int n);
int	my_memcmp(void *s1, void *s2, size_t n);
int	count_word(char *buff);
int	my_strlen_tab(char **env);
int	show_tab(char **tab);
char	*epur_str(char *str);
char	*get_next_line(const int fd);
char	*my_realloc(char *buff, int nb);
char	*my_strdup(char *src);
char	*my_strcpy(char *dest, char *src);
char	**my_str_to_wordtab(char *str, char c);

/* --- END_FCT --- */

/* --- BUILTIN --- */

int	my_env(char **env);
int	find_name(char **env, char *str);
int	check_home(char **env);
int	check_pwd(char **env);
int	check_if_built_exist(char *buff);
int	builtin(char *buff, char **env);
int	check_value_exist_env(char **env, char *buff);
char	*my_cd_oldpath(char **env);
char	*change_path_cd(char *env);
char	**env_tab(char **env);
char	**builtin_env(char *buff, char **env);
char	**overwrite_setenv(char **env, char **tab, int i);
char	**my_unsetenv(char **env, char *buff);
char	**my_setenv(char **env, char *buff);
char	**my_cd(char **env, char *cmd);

/* --- END_BUILTIN --- */

/* --- EXECVE --- */

int	my_execve(char **av, char **env);
int	my_execve_brut(char *path, char **av, char **env);
int	find_if_exist(char *cmd);
int	check_path(char **env);
char	*change_path(char *env);
char	*find_good_cmd(char **path);
char	**get_new_path(char **env, char *buff);

/* --- END_EXECVE --- */

/* --- SIGNAL --- */

void	signal_process();
void	get_sigseg(int sigint);
void	get_sigint(int sigint);

/* --- END_SIGNAL --- */

#endif /* !PROTOTYPES_H_ */
