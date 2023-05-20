#include <iostream>
#include <vector>

using namespace std;

int	N, M;
vector<int>	list;
bool	visited[10];

void	go(int num)
{
	if (list.size() == M)
	{
		for (int a: list)
			cout << a << " ";
		cout << '\n';
		return ;
	}
	for (int i=1; i<=N; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			list.push_back(i);
			go(num + 1);
			visited[i] = false;
			list.pop_back();
		}
	}
}

int	main(void)
{
	cin >> N >> M;

	for (int i=1; i<=N; i++)
	{
		visited[i] = true;
		list.push_back(i);
		go(i);
		visited[i] = false;
		list.pop_back();
	}
}
