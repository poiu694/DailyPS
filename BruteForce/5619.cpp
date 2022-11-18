#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int	digit_len(int num)
{
	int	size;

	size = 0;
	while (num)
	{
		num /= 10;
		size++;
	}
	return (size);
}

int	main(void)
{
	int	N;
	vector<int>	list;
	vector<int>	min4List;

	cin >> N;
	list.resize(N);
	for (int i=0; i<N; i++)
		cin >> list[i];
	sort(list.begin(), list.end());
	for (int i=0; i<4; i++)
		min4List.push_back(list[i]);
	vector<int>	candidate;
	
	int	a;

	a = min4List[0] * pow(10, digit_len(min4List[1])) + min4List[1]; candidate.push_back(a);
	a = min4List[0] * pow(10, digit_len(min4List[2])) + min4List[2]; candidate.push_back(a);
	if (N >= 4)
	{
		a = min4List[0] * pow(10, digit_len(min4List[3])) + min4List[3]; candidate.push_back(a);
	}

	a = min4List[1] * pow(10, digit_len(min4List[0])) + min4List[0]; candidate.push_back(a);
	a = min4List[1] * pow(10, digit_len(min4List[2])) + min4List[2]; candidate.push_back(a);
	if (N >= 4)
	{
		a = min4List[1] * pow(10, digit_len(min4List[3])) + min4List[3]; candidate.push_back(a);
	}

	a = min4List[2] * pow(10, digit_len(min4List[0])) + min4List[0]; candidate.push_back(a);
	a = min4List[2] * pow(10, digit_len(min4List[1])) + min4List[1]; candidate.push_back(a);
	if (N >= 4)
	{
		a = min4List[2] * pow(10, digit_len(min4List[3])) + min4List[3]; candidate.push_back(a);
	}

	if (N >= 4)
	{
		a = min4List[3] * pow(10, digit_len(min4List[0])) + min4List[0]; candidate.push_back(a);
		a = min4List[3] * pow(10, digit_len(min4List[1])) + min4List[1]; candidate.push_back(a);
		a = min4List[3] * pow(10, digit_len(min4List[2])) + min4List[2]; candidate.push_back(a);
	}
	sort(candidate.begin(), candidate.end());
	cout << candidate[2];
}
