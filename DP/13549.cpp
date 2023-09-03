#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

# define MAX	987654321
# define SIZE	200001

int	N, K;
int	dp[SIZE];

int	main(void)
{
	for (int i=0; i<SIZE; i++)
		dp[i] = 987654321;

	cin >> N >> K;
	for (int i=0; i<SIZE; i++)
	{
		if (i <= N)
			dp[i] = N - i;
		else
		{
			if (i % 2 == 0)
				dp[i] = min(dp[i / 2], min(dp[i - 1] + 1, dp[i + 1] + 1));
			else
				dp[i] = min(dp[i - 1] + 1, dp[i + 1] + 1);
		}
		int	temp = i;
		while (temp < SIZE && i != 0)
		{
			dp[temp] = min(dp[temp], dp[i]);
			temp *= 2;
		}
	}
	cout << dp[K];
}
