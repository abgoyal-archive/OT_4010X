

#include "shell.h"
#include "builtins.h"

const struct builtincmd builtincmd[] = {

	{ "command",	bltincmd },
	{ "bg",	bgcmd },
	{ "cd",	cdcmd },
	{ "chdir",	cdcmd },
	{ "echo",	echocmd },
	{ "exp",	expcmd },
	{ "let",	expcmd },
	{ "false",	falsecmd },
#if WITH_HISTORY
	{ "fc",	histcmd },
	{ "inputrc",	inputrc },
#endif
	{ "fg",	fgcmd },
	{ "getopts",	getoptscmd },
	{ "hash",	hashcmd },
	{ "jobid",	jobidcmd },
	{ "jobs",	jobscmd },
	{ "local",	localcmd },
#ifndef SMALL
#endif
	{ "pwd",	pwdcmd },
	{ "read",	readcmd },
	{ "setvar",	setvarcmd },
	{ "true",	truecmd },
	{ "type",	typecmd },
	{ "umask",	umaskcmd },
	{ "unalias",	unaliascmd },
	{ "wait",	waitcmd },
	{ "alias",	aliascmd },
	{ "ulimit",	ulimitcmd },
	{ "wordexp",	wordexpcmd },
	{ 0, 0 },
};

const struct builtincmd splbltincmd[] = {
	{ "break",	breakcmd },
	{ "continue",	breakcmd },
	{ ".",	dotcmd },
	{ "eval",	evalcmd },
	{ "exec",	execcmd },
	{ "exit",	exitcmd },
	{ "export",	exportcmd },
	{ "readonly",	exportcmd },
	{ "return",	returncmd },
	{ "set",	setcmd },
	{ "shift",	shiftcmd },
	{ "times",	timescmd },
	{ "trap",	trapcmd },
	{ ":",	truecmd },
	{ "unset",	unsetcmd },
	{ 0, 0 },
};