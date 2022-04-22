#include <iostream>

using namespace std;

int	main(void)
{
	int		N;
	char	past;
	char	now;
	int		ans;

	cin >> N;
	ans = 1;
	past = '-';
	while (N--)
	{
		cin >> now;
		if (now == past)
			continue ;
		ans += 1;
		past = now;
	}
	cout << ans;
}
