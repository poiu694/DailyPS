#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

bool	visited[1001];
vector<int>	graph[1001];

void	dfs(int node)
{
	visited[node] = true;

	for (int next: graph[node])
		if (!visited[next])
			dfs(next);
}

int	main(void)
{
	int	N, T;
	int node;
	int	cnt;

	cin >> T;
	memset(visited, false, sizeof(visited));
	while (T--)
	{
		cin >> N;

		cnt = 0;
		for (int i=1; i<=N; i++)
		{
			cin >> node;
			graph[i].push_back(node);
		}
		for (int i=1; i<=N; i++)
		{
			if (!visited[i])
			{
				cnt++;
				dfs(i);
			}
		}
		cout << cnt << '\n';
		for (int i=1; i<=N; i++)
			graph[i].clear();
		memset(visited, false, sizeof(visited));
	}


}
