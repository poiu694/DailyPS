#include <iostream>
#include <cstring>
#include <cmath>

# define	MOD 1000000009

using namespace std;

int	N, T;
int	dp[100001];

int	main(void)
{
	cin >> T;

	memset(dp, -1, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 3;
	dp[6] = 6;
	// dp[i]
	// 대칭이 되려면 양 옆에 1, 2, 3을 각각 붙이는 방법밖에 없음
	for (int i=7; i<=100000; i++)
	{
		dp[i] = ((dp[i - 2] + dp[i - 4]) % MOD + dp[i - 6]) % MOD;
	}
	while (T--)
	{
		cin >> N;
		cout << dp[N] << '\n';
	}
}
