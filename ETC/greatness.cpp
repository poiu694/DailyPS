#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int	main(void)
{
	int	N;
	int	answer;
	vector<int>	list;
	vector<int>	frequencies;
	unordered_map<int, int>	frequency;

	cin >> N;
	list.resize(N);
	for (int i=0; i<N; i++)
	{
		cin >> list[i];
		frequency[list[i]]++;
	}
	for (const auto& freq: frequency)
	{
		frequencies.push_back(freq.second);
	}
	sort(frequencies.rbegin(), frequencies.rend());

	answer = 0;
	for (int i=1; i<frequencies.size(); i++)
		answer += frequencies[i];
	cout << answer;
}
