#include "minishell.h"

/*	This function checks the next separator of cmd's
	the first separator on the list is TRUNC (>), so
	if the token is less than TRUNC (3), then steps into
	the next token, and skip is the parameter that tells
	the function to start on the next token
*/
t_token	*next_sep(t_token *token, int skip)
{
	if (token && skip)
		token = token->next;
	while(token && token->type < TRUNC)
		token = token->next;
	return (token);
}

/*	Same thing as the previous one, but this checks the prev
	separator on the cmd, and the skip parameter tells the function
	to start on the previous token
*/
t_token	*prev_sep(t_token *token, int skip)
{
	if (token && skip)
		token = token->prev;
	while(token && token->type < TRUNC)
		token = token->prev;
	return (token);
}

/*	This function checks if the next CMD is really a CMD, if in the
	very first position is a CMD and the previous pos is NULL then
	we can just continue with the loop, or else if we've a CMD and
	the type of token of the previous position is less than the EOC
	(END) then just skip it because it's not a correct separator
*/
t_token	*next_run(t_token *token, int skip)
{
	if (token && skip)
		token = token->next;
	while(token && token->type != CMD)
	{
		if (token && token->type == CMD && token->prev == NULL)
			continue;
		else if (token && token->type == CMD && token->prev->type < END)
			token = token->next;
	}
	return (token);
}