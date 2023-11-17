#include "hsh.h"

/**
 * parse - parse input
 * @dets: shell detsrmation
 *
 * Description: This function expands aliases, variables, and word splitting
 *
 * Return: the final number of tokens
 */
int parse(dets_t *dets)
{
	char **tokens, *tok;
	size_t n = 0;
	cmdlist_t *cmd = dets->commands = cmd_to_list(dets->line);

	while (cmd)
	{
		remove_comments(cmd);
		if (!cmd->tokens)
		{
			cmd = cmd->next;
			del_cmd(&(dets->commands), n);
			continue;
		}
		expand_aliases(dets->aliases, &(cmd->tokens));
		if (!cmd->tokens)
		{
			cmd = cmd->next;
			del_cmd(&(dets->commands), n);
			continue;
		}

		tokens = cmd->tokens;
		for (tok = *tokens; tok; tok = *(++tokens))
		{
			*tokens = dequote(tok);
			free(tok);
		}
		cmd = cmd->next;
		++n;
	}
	return (n);
}
