#include <iostream>

using namespace std;

int	main(void)
{
	int	a, b;

	cin >> a >> b;
	for (int i=1; i<=a; i++)
	{
		if (a % i == 0)
		{
			for (int j=1; j<=b; j++)
			{
				if (b % j == 0)
					cout << i << " " << j << '\n';
			}
		}
	}
}
