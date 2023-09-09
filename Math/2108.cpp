#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;
using pii=pair<int, int>;

int	N;
vector<int>	list;
vector<int>	max_list;
map<int, int>	m;

int	main(void)
{
	double	sum;

	cin >> N;
	sum = 0;
	list.resize(N);
	for (int i=0; i<N; i++)
	{
		cin >> list[i];
		sum += list[i];
		m[list[i]]++;
	}
	sort(list.begin(), list.end());

	cout << (int)floor(sum / N + 0.5) << '\n';
	cout << list[N / 2] << '\n';
	int	max_frequency = -1;
	for (auto iter=m.begin(); iter!=m.end(); iter++)
	{
		if (max_frequency < iter->second)
			max_frequency = iter->second;
	}
	for (auto iter=m.begin(); iter!=m.end(); iter++)
	{
		if (max_frequency == iter->second)
			max_list.push_back(iter->first);
	}
	if (max_list.size() > 1)
		cout << max_list[1] << '\n';
	else
		cout << max_list[0] << '\n';
	cout << list[N - 1] - list[0] << '\n';
}
