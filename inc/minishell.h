/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NightVision <NightVision>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:38:31 by NightVision       #+#    #+#             */
/*   Updated: 2025/08/28 17:38:31 by NightVision      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

//LIBRARIES
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <signal.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>

//TOKENS COMMAND
# define EMPTY 0 // Not cmd available
# define CMD 1 // e.g ls
# define ARG 2 // -l
# define TRUNC 3 // >
# define APPEND 4 // >>
# define INPUT 5 // <
# define PIPE 6 // |
# define END 7 // EOC

//TOKENS I/O
# define STDIN 0 // Input
# define STDOUT 1 // Output
# define STDERR 2 // Error exit

//TOKENS NO-TOKEN-NEEDED
# define SKIP 1 // Skip it, cuz is not a token
# define NO_SKIP 0 // Process that token

//TOKENS CMD-FEATURES
# define BUFF_SIZE 4096 // Buffer of cmd
# define EXPAND -36 // Token needed to be expanded
# define ERR_CODE 1 // Fail code ret
# define SUCCESS_CODE 0 // Success code ret
# define DIR_AS_CMD 126 // Directory treated as cmd
# define NON_CMD 127 // Cmd not found

// LIST 1 -> Save tokens
typedef struct s_token
{
	char			*name; // cmd to tokenize
	int				id; // Nº of token
	struct s_token	*prev; // Previous cmd
	struct s_token	*next; // Next cmd
} t_token;

// LIST 2 -> Look for path
typedef struct s_env
{
	char			*env; // Path of $PATH
	struct s_env	*next; //Next word of that str
} t_env;

// LIST 3 -> Main linked list for the MiniShell
typedef struct s_MS
{
	t_token	*start; // Start the tokenization
	t_env	*private_env; // Internal path
	t_env	*public_env; // Generic path
	int		in; // STDIN
	int		out; // STDOUT
	int		infile; // Infile forwarded through a (<)
	int		outfile; // Outfile forwarded through a (> or >>)
	int		pip_in; // Input through a pipe
	int		pip_out; // Output through a pipe
	int		pid; // PID of the fork
	int		cmd_to_exec; // Is there any cmd to execute yet?
	int		is_parent; // 1 for parent, 0 it's not
	int		ret_code; // Return code of the last command executed
	int		last; // State of the last command
	int		exit; // Flag to the MiniShell to exit
	int		crash; // It (The MS) won't execute due to an err
} t_MS;

typedef struct s_signal
{
	int		SI; // SIGINT (CTRL + C)
	int		SQ; // SIGQUIT (CTRL + /)
	int		exit_stat;
	pid_t	pid;
} t_signal;

typedef struct s_expand
{
	char	*new_arg; // Variable expanded
	int		i; // Iterate over the original string
	int		j; // Iterate over the expanded string
} t_expand;

#endif