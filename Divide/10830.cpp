#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <limits.h>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<vector<long long>> MultiMatrix(vector<vector<long long>> a, vector<vector<long long>> b)
{
    vector<vector<long long>> ret(a.size(), vector<long long>(a.size()));

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            for (int k = 0; k < a.size(); k++)
            {
                ret[i][j] += a[i][k] * b[k][j];
            }
            ret[i][j] %= 1000;
        }
    }

    return ret;
}

void solve()
{
    long long N;
    long long B;
    cin >> N >> B;

    vector<vector<long long>> matrix(N, vector<long long>(N));
    vector<vector<long long>> ans = matrix;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];

    for (int i = 0; i < N; i++)
        ans[i][i] = 1;
    while (B > 0)
    {
        if (B & 1)
        {
            ans = MultiMatrix(ans, matrix);
        }

        matrix = MultiMatrix(matrix, matrix);
        B = B >> 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}

int main()
{
    fastIO();
    solve();
}
