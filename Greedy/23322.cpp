#include <iostream>
#include <vector>

using namespace std;

void	fastIO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

pair<int, int> get_answer(int N, int K, vector<int> &list)
{
	int	day;
	int	chocolate;

	day = 0;
	chocolate = 0;
	for (int i=1; i<N; i++)
	{
		if (list[i] != list[0])
		{
			day++;
			chocolate += list[i] - list[0];
		}
	} 
	return {chocolate, day};
}

void	get_solution(void)
{
	int				N, K;
	pair<int, int>	ans;
	vector<int>		list;

	cin >> N >> K;
	list.resize(N);
	for (int i=0; i<N; i++)
		cin >> list[i];
	ans = get_answer(N, K, list);
	cout << ans.first << " " << ans.second;
}

int	main(void)
{
	fastIO();
	get_solution();
}
