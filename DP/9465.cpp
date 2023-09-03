#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int	T;
int	N;
vector<int>	list[2];
int	dp[2][100001];

int	max_score(void)
{
	memset(dp, 0, sizeof(dp));

	dp[0][0] = list[0][0];
    dp[1][0] = list[1][0];
    dp[0][1] = list[0][1] + dp[1][0];
    dp[1][1] = list[1][1] + dp[0][0];
	for (int i=2; i<N; i++)
	{
		dp[0][i] = list[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
		dp[1][i] = list[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
	}
	return (max(dp[0][N - 1], dp[1][N - 1]));
}

int	main(void)
{
	cin >> T;

	while (T--)
	{
		list[0].clear();
		list[1].clear();

		cin >> N;
		for (int i=0; i<2; i++)
		{
			list[i].resize(N);
			for (int j=0; j<N; j++)
				cin >> list[i][j];
		}
		cout << max_score() << '\n';
	}
}
