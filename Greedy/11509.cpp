#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int	main(void)
{
	int	N;
	int	ans;
	int	ballonHeight;
	vector<int>	list;
	vector<int>	arrow(1000001);

	cin >> N;
	list.resize(N);
	for (int i=0; i<N; i++)
		cin >> list[i];

	// Solution
	ans = 0;
	for (int i=0; i<N; i++)
	{
		ballonHeight = list[i];
		// isExistUpperArrow in prev
		if (arrow[ballonHeight])
		{
			// arrow goes down by hitting ballon
			arrow[ballonHeight]--;
			arrow[ballonHeight - 1]++;
		}
		else
		{
			ans++;
			// arrow goes down by hitting ballon
			arrow[ballonHeight - 1]++;
		}
	}
	cout << ans;
}
