#include <iostream>

using namespace std;

int	main(void)
{
	long long	m;
	long long	a, b, c;
	string		ans;

	cin >> a >> b >> c;
	m = a * b % c;
	cout << a * b / c<< ".";
	for (int i=0; i<10; i++)
	{
		m *= 10;
		cout << m / c;
		m %= c;
	}
}
