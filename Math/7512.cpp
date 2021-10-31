#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace	std;

# define MAX_SIZE 1e7

void	ft_fastIO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int>	ft_get_prime_list(void)
{
	vector<bool>	visited;
	vector<int>		ret;

	visited.resize(MAX_SIZE, false);
	for (long long i=2; i<MAX_SIZE; i++)
	{
		if (visited[i])
			continue;
		ret.push_back(i);
		for (long long j=i*i; j<MAX_SIZE; j+=i)
		{
			visited[j] = true;
		}
	}
	return (ret);
}

vector<long long>	ft_get_sum_prime_list(vector<int> &primeList)
{
	long long			sum;
	vector<long long>	ret;

	sum = 0;
	ret.push_back(0);
	for (int i=0; i<primeList.size(); i++)
	{
		sum = ret[ret.size() - 1] + primeList[i];
		ret.push_back(sum);
	}
	return (ret);
}

int	ft_get_min_intersection(vector<int> &list, int m)
{
	int	ret;

	ret = 0;
	for (int i=1; i<MAX_SIZE; i++)
	{
		if (list[i] == m)
		{
			ret = i;
			break ;
		}
	}
	return (ret);
}

void	ft_print_solution(int index, int T, int ans)
{
	cout << "Scenario " << index << ":\n";
	cout << ans << '\n';
	if (index != T) cout << '\n';
}

void	ft_get_solution(void)
{
	int					T, m, n;
	int					ans;
	long long			temp;
	vector<int>			cntList, primeList;
	vector<long long>	primeSumList;

	cin >> T;
	primeList = ft_get_prime_list();
	primeSumList = ft_get_sum_prime_list(primeList);
	for (int i=1; i<=T; i++)
	{
		cin >> m;
		cntList.clear();
		cntList.resize(MAX_SIZE + 1, 0);
		for (int j=0; j<m; j++)
		{
			cin >> n;
			for (int k=n; k<primeSumList.size(); k++)
			{
				temp = primeSumList[k] - primeSumList[k - n];
				if (temp >= MAX_SIZE)
					break ;
				cntList[temp]++;
			}
		}
		ans = ft_get_min_intersection(cntList, m);
		ft_print_solution(i, T, ans);
	}
}

int	main(void)
{
	ft_fastIO();
	ft_get_solution();
}
