#include <iostream>

using namespace std;

int	main(void)
{
	int	T;
	int	a, b, c;

	cin >> T;
	while (T--)
	{
		cin >> a >> b >> c;
		if (b <= c)
			cout << 0;
		else
			cout << b - c;
		cout << " ";
		if (b + c <= a)
			cout << b;
		else
			cout << a - c;
		cout << '\n';
	}
}
