#include <iostream>

using namespace std;

int	main(void)
{
	unsigned long long	N;

	cin >> N;
	if (N == 1)
		cout << 1;
	else
		cout << 2 * N - 2;
}
