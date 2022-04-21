#include <iostream>

using namespace std;

int	main(void)
{
	int			T;
	long long	a, b;

	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		b = b + (b * (b + 1) / 2);
		cout << a << " " << b << '\n';
	}
}
