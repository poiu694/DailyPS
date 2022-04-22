#include <iostream>
#include <cmath>

using namespace std;

int	main(void)
{
	int	T;
	int	k, x, y;
	int	ans;

	cin >> T;
	while (T--)
	{
		cin >> k >> x >> y;
		ans = 0;

		while ((x < k && y < k) || abs(x - y) < 2)
		{
			if (x > y)
				x++;
			else
				y++;
			ans++;
		}
		cout << ans << '\n';
	}
}
