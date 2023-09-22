#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

int	N;
long long	list[1000001];
long long	dp[1000001];
long long	answer;

// dp[i] = max(dp[i - 1] + list[i], list[i])
int	main(void)
{
	cin >> N;
	for (int i=0; i<N; i++)
		cin >> list[i];
	
	memset(dp, -1, sizeof(dp));
	dp[0] = list[0];
	for (int i=1; i<N; i++)
		dp[i] = max(dp[i - 1] + list[i], list[i]);
	answer = LONG_MIN;

	for (int i=0; i<N; i++)
		answer = max(answer, dp[i]);
	cout << answer;
}
