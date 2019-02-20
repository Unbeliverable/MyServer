int parse_command(string& command, char **args)
{
	int argc = 0;
	size_t pos = 0;
	size_t tpos = pos;

	command += ' ';

	pos = command.find_first_not_of(' ', pos);
	if (pos == string::npos)
		return argc;

	while ((tpos = command.find_first_of(' ', pos)) != string::npos) {
		args[argc] = &command[pos];
		command[tpos] = '\0';
		argc++;

		pos = command.find_first_not_of(' ', tpos + 1);
		if (pos == string::npos)
			break;
	}

	return argc;
}

#define MAXSIZE 256
