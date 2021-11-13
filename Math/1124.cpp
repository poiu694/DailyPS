#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void	fast_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int>	get_prime_list(void)
{
	vector<bool>	visited;
	vector<int>		list;

	visited.resize(100002, false);
	for (int i=2; i<=100000; i++)
	{
		if (visited[i])
			continue ;
		for (int j=2*i; j<=sqrt(100000); j+=i)
			visited[j] = true;
	}
	for (int i=2; i<=100000; i++)
		if (!visited[i])
			list.push_back(i);
	return (list);
}

bool	is_under_prime_number(int n, vector<int> &primeList)
{
	int index;
	int	primeCnt;

	index = 0;
	primeCnt = 0;
	while (n != 1 and index < primeList.size())
	{
		if (n % primeList[index] == 0)
		{
			n /= primeList[index];
			primeCnt++;
		}
		else
			index++;
	}
	for (int i=0; i<primeList.size(); i++)
		if (primeCnt == primeList[i])
			return (true);
	return (false);
}

int	get_cnt_under_prime(int A, int B, vector<int> &primeList)
{
	int	ret;

	ret = 0;
	for (int i=A; i<=B; i++)
		if (is_under_prime_number(i, primeList))
			ret++;
	return (ret);
}

void	get_solution(void)
{
	int			A, B;
	int			ans;
	vector<int>	primeList;

	cin >> A >> B;
	primeList = get_prime_list();
	ans = get_cnt_under_prime(A, B, primeList);
	cout << ans;
}

int	main(void)
{
	fast_io();
	get_solution();
}
