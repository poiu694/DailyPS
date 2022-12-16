int combination(int n, int r)
{
  int dp[10001][10001];

  for (int i=0; i<=n; i++)
  {
    for (int j=0; j<=r; j++)
    {
      if (i == j || j == 0)
      {
        dp[i][j] = 0;
      }
      else
      {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }
    }
  }
  return dp[n][r];
}