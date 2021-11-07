#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void	fastIO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void	get_solution(void)
{
	int						N, M;
	int						i, j;
	vector<int>				list1, list2, list3;
	vector<int>::iterator	it;

	cin >> N >> M;
	list1.resize(N);
	list2.resize(M);
	list3.resize(N + M);
	i = 0; j = 0;
	while (N or M)
	{
		if (N)
		{
			cin >> list1[i++];
			N--;
		}
		else
		{
			cin >> list2[j++];
			M--;
		}
	}
	sort(list1.begin(), list1.end());
	sort(list2.begin(), list2.end());
	it = set_intersection(list1.begin(), list1.end(), list2.begin(), list2.end(), list3.begin());
	cout << (i + j ) - 2 * (it - list3.begin());
}

int	main(void)
{
	fastIO();
	get_solution();
}
