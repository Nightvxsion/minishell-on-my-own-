#include "minishell.h"

/*	This function at first checks if there's more than 1 cmd
	if it's that then goes into the loop and frees the name of
	the token, goes to the next one, and deletes de information
	of the previous one.
	If there's only one cmd then frees the name of the token and
	frees the info of that single token
*/

void	free_token(t_token *first_token)
{
	while (first_token && first_token->next)
	{
		pointer_free(first_token->name);
		first_token = first_token->next;
		pointer_free(first_token->prev);
	}
	if (first_token)
	{
		pointer_free(first_token->name);
		pointer_free(first_token);
	}
}

/*	This function frees the enviromental path, first we'll call
	a reference to the very first position of the $PATH called tmp
	then while that path exists itself. First we put the env to tmp
	(that's the first pos), then with env only we're going to step over
	and we're going to be freeing with tmp the value inside of $PATH
*/

void	free_env(t_env *env)
{
	t_env *tmp;

	while(env && env->next)
	{
		tmp = env;
		env = env->next;
		pointer_free(tmp->env);
		pointer_free(tmp);
	}
	pointer_free(tmp->env);
	pointer_free(tmp);
}

/*	This function only frees the matrices nothing more lol */

void	free_tabs(char **tab)
{
	int i = 0;

	while (tab[i])
	{
		if (tab[i])
			pointer_free(tab[i]);
		i++;
	}
	if (tab)
		pointer_free(tab);
}