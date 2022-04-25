#include <iostream>

using namespace std;

int	main(void)
{
	int		sum;
	string	str;

	getline(cin, str);
	sum = 0;
	for (int i=0; i<str.length(); i++)
		sum += str[i];
	cout << char(sum / str.length());
}

