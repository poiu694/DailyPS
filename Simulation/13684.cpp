#include <iostream>

using namespace std;

int	main(void)
{
	int	T;
	int	bx, by;
	int	x, y;

	while (true)
	{
		cin >> T;
		if (T == 0)
			break ;
		cin >> bx >> by;
		while (T--)
		{
			cin >> x >> y;
			if (bx == x || by == y)
				cout << "divisa\n";
			else if (bx > x && by > y)
				cout << "SO\n";
			else if (bx > x && by < y)
				cout << "NO\n";
			else if (bx < x && by > y)
				cout << "SE\n";
			else
				cout << "NE\n";
		}
	}
}
