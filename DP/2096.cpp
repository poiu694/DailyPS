#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int	N;
short	board[100001][3]; // 1,200,000
int	dp[100001][3]; // 1,200,000

int	main(void)
{
	int	maxValue, minValue;

	cin >> N;
	for (int i=0; i<N; i++)
		for (int j=0; j<3; j++)
			cin >> board[i][j];

	// maxDP
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<3; i++)
		dp[0][i] = board[0][i];
	for (int i=1; i<N; i++)
	{
		dp[i][0] = board[i][0] + max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = board[i][1] + max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		dp[i][2] = board[i][2] + max(dp[i - 1][1], dp[i - 1][2]);
	}
	maxValue = max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2]));

	// minDP
	memset(dp, 1, sizeof(dp));
	for (int i=0; i<3; i++)
		dp[0][i] = board[0][i];
	for (int i=1; i<N; i++)
	{
		dp[i][0] = board[i][0] + min(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = board[i][1] + min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
		dp[i][2] = board[i][2] + min(dp[i - 1][1], dp[i - 1][2]);
	}
	minValue = min(dp[N-1][0], min(dp[N-1][1], dp[N-1][2]));

	cout << maxValue << " " << minValue << '\n';
}
