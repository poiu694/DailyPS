#include <iostream>
#include <cmath>

using namespace std;

bool	can_move(int x1, int y1, int x2, int y2)
{
	if (abs(x1 - x2) == 1 && abs(y1 - y2) == 2)
		return (true);
	if (abs(x1 - x2) == 2 && abs(y1 - y2) == 1)
		return (true);
	return (false);
}

int	main(void)
{
	int	T;
	int	n;
	int	r, c;
	int	x, y;

	cin >> T;
	for (int now=1; now<=T; now++)
	{
		cin >> n >> r >> c >> x >> y;

		cout << "Case " << now << ": ";
		if (can_move(r, c, x, y))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
