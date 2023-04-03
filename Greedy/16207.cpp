#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int	main(void)
{
	int	N;
	long long	ans;
	priority_queue<int>	pq;

	ans = 0;
	cin >> N;
	while (N--)
	{
		int	a;
		cin >> a;
		pq.push(a);
	}
	long long	width;
	long long	past;
	long long	current;
	past = width = current = 0;
	while (!pq.empty())
	{
		current = pq.top();
		pq.pop();

		if (width && (past == current || past - 1 == current))
		{
			ans += min(past, current) * width;
			past = width = 0;
		}
		else if (past == current || past - 1 == current)
		{
			width = min(past, current);
			past = 0;
		}
		else
		{
			past = current;
		}
	}
	cout << ans;
}
