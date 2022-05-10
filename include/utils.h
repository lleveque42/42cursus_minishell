/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:52:06 by arudy             #+#    #+#             */
/*   Updated: 2022/05/10 11:59:16 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_open(char *filename, int flags, int mod, t_data *data);
void	sig_reset(void);
void	sig_fork(int sig);
void	sig_handler(int sig);
void	sig_heredoc(int sig);
void	free_lst(t_data *data);
void	free_all(t_data *data);
void	close_all(t_data *data);
void	sig_handler_heredoc(void);
void	print_fd_error(t_data *data);
void	ft_free(void *ptr, t_data *data);
void	free_env(t_env *lst, t_data *data);
void	ft_free_garbage(t_garbage *garbage);
void	*ft_malloc(size_t size, t_data *data);
void	*error(char *cmd, char *arg, char *msg);
void	free_cmd_lst(t_cmd **lst, t_data *data);
void	set_env(t_env *env, t_data *data, char *var, char *value);
char	**dup_env(t_env *env, t_data *data);
char	*get_prompt(t_data *data, char **envp);
t_data	*init_data(char **envp);
t_token	*new_fd_error(t_token *lst, t_data *data);

#endif
