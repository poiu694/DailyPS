#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef	struct	s_cnt
{
	int	t_cnt;
	int	g_cnt;
	int	f_cnt;
	int	p_cnt;
}	t_cnt;

void	init_list(int N, vector<t_cnt> &list)
{
	list.resize(N + 1);
	for (int i=0; i<=N; i++)
	{
		list[i].t_cnt = 0;
		list[i].g_cnt = 0;
		list[i].f_cnt = 0;
		list[i].p_cnt = 0;
	}
}

int	get_state(t_cnt list)
{
	int	ret;

	ret = 0;
	ret += 27 * (list.t_cnt % 3);
	ret += 9 * (list.g_cnt % 3);
	ret += 3 * (list.f_cnt % 3);
	ret += 1 * (list.p_cnt % 3);
	return (ret);
}


// 0 2 0 3 0 4 0 5 0
int	get_cnt(int n)
{
	return (n * (n + 1) / 2);
}

int	main(void)
{
	int				N;
	int				ans;
	string			target;
	int				visited[100];
	vector<t_cnt>	list;

	cin >> N >> target;
	init_list(N, list);
	for (int i=0; i<N; i++)
	{
		list[i + 1] = list[i];
		if (target[i] == 'T')
			list[i + 1].t_cnt += 1;
		if (target[i] == 'G')
			list[i + 1].g_cnt += 1;
		if (target[i] == 'F')
			list[i + 1].f_cnt += 1;
		if (target[i] == 'P')
			list[i + 1].p_cnt += 1;
	}
	ans = 0;
	memset(visited, 0, sizeof(visited));
	for (int i=0; i<=N; i++)
		visited[get_state(list[i])] += 1;
	for (int i=0; i<100; i++)
	{
		if (visited[i] > 1)
			ans += get_cnt(visited[i] - 1);
	}
	cout << ans;
}
