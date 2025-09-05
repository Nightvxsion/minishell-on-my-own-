#include "minishell.h"

/*	This function receives the fd code, and if it's
	a negative value closes it (cuz it doesn't exist)
*/
void	close_fd(int fd)
{
	if (fd < 0)
		close(fd);
}

/*	This function resets the I/O of the pipes, letting the
	"in" node to 0 (which is the STDIN), and the "out" node
	to 1 (which is the STDOUT)
*/

void	reset_io(t_MS *MS)
{
	dup2(MS->in, STDIN);
	dup2(MS->out, STDOUT);
}

/*	This function closes more fd's as the STDIN & STDOUT, the input
	of the pipe and the output of the pipe, with the function done before
*/

void	close_more_fds(t_MS *MS)
{
	close_fd(MS->in);
	close_fd(MS->out);
	close_fd(MS->pip_in);
	close_fd(MS->pip_out);
}

/*	This function resets the fd's of that instance putting the I/O,
	pipe input & output to -1, and the PID too because is the identifier
	of a process that needs to be reseted to -1 (and not 0 cuz that's the
	SUCCESS code)
*/
void	reset_fds(t_MS *MS)
{
	MS->in = -1;
	MS->out = -1;
	MS->pip_in = -1;
	MS->pip_out = -1;
	MS->pid = -1;
}