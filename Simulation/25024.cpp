#include <iostream>

using namespace std;

bool	is_can_read_day(int x, int y)
{
	if (!(1 <= x && x <= 12))
		return (false);
	switch (x)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (1 <= y && y <= 31)
				return (true);
			else
				break ;
		case 2:
			if (1 <= y && y <= 29)
				return (true);
			else
				break ;
		case 4:
		case 6:
		case 9:
		case 11:
			if (1 <= y && y <= 30)
				return (true);
			else
				break ;
		default:
			break ;
	}
	return (false);
}

int	main(void)
{
	int	T;
	int	x, y;

	cin >> T;
	while (T--)
	{
		cin >> x >> y;
		if (0 <= x && x <= 23 && 0 <= y && y <= 59)
			cout << "Yes ";
		else
			cout << "No ";
		if (is_can_read_day(x, y))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
