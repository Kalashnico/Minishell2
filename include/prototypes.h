/*
** prototypes.h for prototypes in /home/guerin_n/Epitech/Shell/PSU_2016_minishell1
** 
** Made by Nicolas Guerin
** Login   <guerin_n@epitech.net>
** 
** Started on  Mon Jan  9 15:46:26 2017 Nicolas Guerin
** Last update Thu Apr  6 16:23:45 2017 Nicolas
*/

#ifndef PROTOTYPES_H_
# define PROTOTYPES_H_

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

/* --- MACRO --- */

# define RED                    "\033[1;31m"
# define GREEN                  "\033[1;32m"
# define CYAN                   "\033[1;36m"
# define BLUE                   "\033[1;34m"
# define YELLOW                 "\033[1;33m"
# define WHITE			"\033[0;m"

/* --- END_MACRO --- */

void	prompt();
void	init_shell();

/* ---  FCT --- */

void	my_putchar(char c, int fd);
void	my_putstr(char *str, int fd);
void	free_tab(char **av);
void	my_memset(void *s, int f, int n);
void	my_strcat(char *dest, char *src);
int	find_pos_equal(char *path);
int	my_getnbr(char *str);
int	my_strlen(char *str);
int	my_strncmp(char *s1, char *s2, int n);
int	my_strcmp(char *s1, char *s2);
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
int	find_pwd(char **env);
int	find_oldpwd(char **env);
int	check_home(char **env);
int	check_pwd(char **env);
int	check_if_built_exist(char *buff);
int	builtin(char *buff, char **env);
int	check_value_exist_env(char **env, char *buff);
char	*my_cd_oldpath(char **env);
char	*change_path_cd(char *env);
char	*get_old_pwd(char *str);
char	*get_pwd(char *str);
char	*cd_oldpwd(char **env);
char	**env_tab(char **env);
char	**builtin_env(char *buff, char **env);
char	**overwrite_setenv(char **env, char **tab, int i);
char	**my_unsetenv(char **env, char *buff);
char	**my_setenv(char **env, char *buff);
char	**my_cd(char **env, char *cmd);
char	**change_pwd(char **env, char *cmd);

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
void	get_sigabrt(int sigint);

/* --- END_SIGNAL --- */

#endif /* !PROTOTYPES_H_ */
