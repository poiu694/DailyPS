#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
using psi=pair<string, int>;

string english_number[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int	main(void)
{
	int	N, M;
	vector<psi>	list;

	cin >> N >> M;
	for (int num=N; num<=M; num++)
	{
		int	ten_digit = num / 10;
		int one_dight = num % 10;

		if (num >= 10)
			list.push_back({ english_number[ten_digit] + " " + english_number[one_dight], num });
		else
			list.push_back({ english_number[one_dight], num });
	}
	sort(list.begin(), list.end());
	int cnt = 0;
	for (int i=0; i<list.size(); i++)
	{
		cout << list[i].second << " ";
		cnt++;
		if (cnt % 10 == 0)
			cout << '\n';
	}
}
