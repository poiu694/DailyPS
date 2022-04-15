#include <iostream>

using namespace std;

int	main(void)
{
	int	A, B, C;

	cin >> A >> B >> C;
	if (A <= C && C < B)
		cout << 1;
	else
		cout << 0;
}
