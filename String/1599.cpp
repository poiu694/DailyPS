#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

void	fast_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int	getMinsikIndex(unsigned char target)
{
	int		i;
	string	minsik = "abkdeghilmnngoprstuwy";

	for (i=0; i<minsik.length(); i++)
		if (minsik[i] == target)
			return (i);
	return (-1);
}

bool compare(string b, string a)
{
	int		i;

	i = 0;
	while (i<a.length() && i<b.length() && a[i] == b[i])
	{
		if (a[i] == 'n' && b[i] == 'n')
		{
			i++;
			if (a[i] == 'g' && b[i] != 'g')
				return (true);
			if (a[i] != 'g' && b[i] == 'g')
				return (false);
			continue ;
		}
		i++;
	}
	return (getMinsikIndex((unsigned char)b[i]) < getMinsikIndex((unsigned char)a[i]));
}

void	get_solution(void)
{
	int				N;
	vector<string>	list;

	cin >> N;
	list.resize(N);
	for (int i=0; i<N; i++)
		cin >> list[i];
	sort(list.begin(), list.end(), compare);
	for (string str: list)
		cout << str << '\n';
}

int	main(void)
{
	fast_io();
	get_solution();
}
