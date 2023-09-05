#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int	N, M;
vector<bool>	breakdown(10, false);

bool	check(int current)
{
	string	str;

	str = to_string(current);
	for (char ch: str)
	{
		if (breakdown[ch - '0'])
			return (false);
	}
	return (true);
}

int	main(void)
{
	int	temp;
	int	answer;

	cin >> N >> M;
	for (int i=0; i<M; i++)
	{
		cin >> temp;
		breakdown[temp] = true;
	}
	
	answer = abs(N - 100);
	for (int i=0; i<1000000; i++)
	{
		if (check(i))
		{
			temp = abs(N - i) + to_string(i).length();
			answer = min(answer, temp);
		}
	}
	cout << answer;
}
