#include "hsh.h"

/**
 * parse_dets - This is used to resolve the dets tokens
 * @dets: This is the shell details to resolve
 * Return: This returns the total number tokens
*/
int parse_dets(dets_t *dets)
{
	char **tokens;
	const char *delim = " ";
	size_t n_tokens;

	tokens = split_string(dets->line, delim);
	for (n_tokens = 0; tokens[n_tokens] != NULL; n_tokens++)
		;
	dets->tokens = tokens;
	return (n_tokens);
}

/**
 * free_tokens - This is used to free the tokens and each token
 * @tokens: This is a pointer to an array of tokens
*/
void free_tokens(char ***tokens)
{
	char **tok;

	if (!tokens)
		return;

	tok = *tokens;
	if (!tok)
		return;

	while (*tok)
		free(*tok++);
	free(*tokens);

	*tokens = NULL;
}