#include <iostream>

using namespace std;

bool	is_TAK(long long N)
{
	if (N % 3 == 2)
		return (true);
	if (N % 9 == 0)
		return (true);
	return (false);
}

int	main(void)
{
	int			T;
	long long	N;

	cin >> T;
	while (T--)
	{
		cin >> N;
		if (is_TAK(N))
			cout << "TAK\n";
		else
			cout << "NIE\n";
	}
}
