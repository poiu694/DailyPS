#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int	T;
int	N;
vector<string>	list;

int	diff_mbti_score(string A, string B)
{
	int	result;

	result = 0;
	for (int i=0; i<4; i++)
	{
		if (A[i] != B[i])
			result += 1;
	}
	return (result);
}

int	min_diff_mbti_score(void)
{
	int	sum;
	int	result;

	result = 987654321;
	for (int i=0; i<list.size(); i++)
	{
		for (int j=i+1; j<list.size(); j++)
		{
			for (int k=j+1; k<list.size(); k++)
			{
				sum = diff_mbti_score(list[i], list[j]) + diff_mbti_score(list[i], list[k])
						+ diff_mbti_score(list[j], list[k]);
				result = min(sum, result);
			}
		}
	}
	return (result);
}

int	main(void)
{
	cin >> T;

	while (T--)
	{
		string	str;

		cin >> N;
		list.clear();
		list.resize(N);
		for (int i=0; i<N; i++)
			cin >> list[i];

		if (N > 32)
			cout << 0 << '\n';
		else
			cout << min_diff_mbti_score() << '\n';
	}
}
