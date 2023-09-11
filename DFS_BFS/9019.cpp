#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

# define MOD	10000

using namespace std;
using pis=pair<int, string>;

int	T;
bool	visited[20001];

int	d_register(int n)
{
	return ((n * 2) % MOD);
}

int	s_register(int n)
{
	if (n == 0)
		return (9999);
	return (n - 1);
}

// 5137 => 1375
// 137 => 1370 => 1375
int	l_register(int n)
{
	int	temp;

	temp = n;
	n = (n % 1000) * 10;
	n += temp / 1000;
	return (n);
}

// 5137 => 7513
// 513 => 7513
int	r_register(int n)
{
	int	temp;

	temp = n;
	n = (n / 10);
	n += (temp % 10) * 1000;
	return (n);
}

string	bfs(int start, int goal)
{
	queue<pis>	q;

	memset(visited, false, sizeof(visited));
	q.push({ d_register(start), "D" });
	visited[d_register(start)] = true;
	q.push({ s_register(start), "S" });
	visited[s_register(start)] = true;
	q.push({ l_register(start), "L" });
	visited[l_register(start)] = true;
	q.push({ r_register(start), "R" });
	visited[r_register(start)] = true;
	while (!q.empty())
	{
		int	n = q.front().first;
		string move = q.front().second;
		q.pop();

		if (n == goal)
			return (move);
		if (!visited[d_register(n)])
		{
			q.push({ d_register(n), move + "D" });
			visited[d_register(n)] = true;
		}
		if (!visited[s_register(n)])
		{
			q.push({ s_register(n), move + "S" });
			visited[s_register(n)] = true;
		}
		if (!visited[l_register(n)])
		{
			q.push({ l_register(n), move + "L" });
			visited[l_register(n)] = true;
		}
		if (!visited[r_register(n)])
		{
			q.push({ r_register(n), move + "R" });
			visited[r_register(n)] = true;
		}
	}

	return "";
}


int	main(void)
{
	cin >> T;

	while (T--)
	{
		int a, b;

		cin >> a >> b;
		cout << bfs(a, b) << '\n';
	}
}
