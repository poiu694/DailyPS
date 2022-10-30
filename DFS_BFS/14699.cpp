#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int	dp[5001];

int	dfs(vector<int> graph[5001], int node)
{
	if (node >= 0 && dp[node] != -1)
	{
		return (dp[node]);
	}
	for (int next: graph[node])
	{
		dp[node] = max(dp[node], dfs(graph, next)); 
	}
	return (++dp[node]);
}

int	main(void)
{
	int	n, m;
	vector<int>	height;
	vector<int>	graph[5001];

	cin >> n >> m;
	height.resize(n + 1);
	for (int i=1; i<=n; i++)
		cin >> height[i];
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<m; i++)
	{
		int	a, b;
		cin >> a >> b;
		if (height[a] > height[b])
		{
			graph[b].push_back(a);
		}
		else
		{
			graph[a].push_back(b);
		}
	}
	for (int i=1; i<=n; i++)
		cout << dfs(graph, i) + 1<< '\n';
}
