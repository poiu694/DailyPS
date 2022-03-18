#include <iostream>
#include <cstring>
#include <vector>

# define MOD 1000000007

using namespace std;

void	fast_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int	dfs(vector<int> list[], bool visited[], int node)
{
	int	node_cnt;

	if (visited[node])
		return (0);
	node_cnt = 1;
	visited[node] = true;
	for (auto child: list[node])
		if (!visited[child])
			node_cnt += dfs(list, visited, child);
	return (node_cnt);
}

void	get_solution(void)
{
	int			N, M;
	long long	ans, node_cnt;
	bool		visited[200001];
	vector<int>	list[200001];

	// input
	cin >> N >> M;
	for (int i=0; i<M; i++)
	{
		int	a, b;
		cin >> a >> b;
		list[a].push_back(b);
		list[b].push_back(a);
	}
	// solve
	memset(visited, false, sizeof(visited));
	ans = 1;
	for (int i=1; i<=N; i++)
	{
		if (!visited[i])
		{
			node_cnt = dfs(list, visited, i);
			ans = (ans * node_cnt) % MOD;
		}
	}
	cout << ans;
}

int	main(void)
{
	fast_io();
	get_solution();
}
