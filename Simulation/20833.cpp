#include <iostream>
#include <cmath>

using namespace std;

int	main(void)
{
	int			N;
	long long	sum;

	cin >> N;
	sum = 0;
	for (int i=1; i<=N; i++)
	{
		sum += pow(i, 3);
	}
	cout << sum;
}	
