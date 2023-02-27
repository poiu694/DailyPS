string	trim0_start(string target)
{
	string	result;

	result = target;
	while (result.length() && result[0] == '0')
	{
		result = result.substr(1);
	}
	return (result);
}