#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>	bfs(int N, vector<int> graph[200001], vector<int> list)
{
	int	time;
	int	node, count;
	queue<int>	q;
	vector<int>	ret;
	vector<int> past;

	ret.resize(N + 1, -1);
	past.resize(N + 1);
	for (int n: list)
	{
		ret[n] = 0;
		q.push(n);
	}
	time = 0;
	while (!q.empty())
	{
		for (int i=0; i<q.size(); i++)
		{
			node = q.front();
			q.pop();

			for (int j=1; j<=N; j++)
				past[j] = ret[j];
			for (int next: graph[node])
			{
				if (past[next] == -1)
				{
					count = 0;
					for (int k=0; k<graph[next].size(); k++)
					{
						if (past[graph[next][k]] != -1 && past[graph[next][k]] <= time)
						{
							count++;
						}
					}
					if (count >= ((graph[next].size() + 1) / 2))
					{
						ret[next] = time + 1;
						q.push(next);
					}
				}
			}
		}
		time++;
	}
	return (ret);
}

int	main(void)
{
	int	N, M, node;
	vector<int>	graph[200001];
	vector<int>	init_known_rumor_list;
	vector<int>	answer;

	cin >> N;
	for (int i=1; i<=N; i++)
	{
		while (cin >> node)
		{
			if (node == 0)
				break ;
			graph[i].push_back(node);
		}
	}
	cin >> M;
	init_known_rumor_list.resize(M);
	for (int i=0; i<M; i++)
	{
		cin >> init_known_rumor_list[i];
	}
	answer = bfs(N, graph, init_known_rumor_list);
	for (int i=1; i<=N; i++)
	{
		cout << answer[i] << '\n';
	}
}
