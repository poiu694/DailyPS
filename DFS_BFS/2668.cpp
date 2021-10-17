#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int			N;
bool		visited[101];
vector<int>	ans;
vector<int> list;

void	ft_fastIO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void	ft_go(int now_node, int start_node)
{
	int	next_node;

	if (visited[now_node])
	{
		if (now_node == start_node) // correct answer
		{
			ans.push_back(start_node);
		}
	}
	else
	{
		visited[now_node] = 1;
		next_node = list[now_node];
		ft_go(next_node, start_node);
	}
}

void	ft_print_answer(void)
{
	cout << ans.size() << '\n';
	for (int i=0; i<ans.size(); i++)
		cout << ans[i] << '\n';
}

void	ft_init(void)
{
	cin >> N;
	list.resize(N + 1);
	for (int i=1; i<=N; i++)
		cin >> list[i];
}

void	ft_find_solution(void)
{
	for (int i=1; i<=N; i++)
	{
		memset(visited, false, sizeof(visited));
		ft_go(i, i);
	}
}

void	ft_solve(void)
{
	ft_init();
	ft_find_solution();	
	ft_print_answer();
}

int	main(void)
{
	ft_fastIO();
	ft_solve();
}
