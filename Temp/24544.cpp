#include <iostream>
#include <vector>

using namespace std;

int	main(void)
{
	int			N;
	int			sum;
	int			isMyView;
	vector<int>	list;

	cin >> N;
	list.resize(N);
	sum = 0;
	for (int i=0; i<N; i++)
	{
		cin >> list[i];
		sum += list[i];
	}
	cout << sum << '\n';
	for (int i=0; i<N; i++)
	{
		cin >> isMyView;
		if (isMyView)
			sum -= list[i];
	}
	cout << sum << '\n';
}
