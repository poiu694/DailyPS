#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int N;
    long long K;
    cin >> N >> K;

    vector<int> list(N + 1);

    int start = 1;
    int end = N;
    for (int i = 1; i <= N; i++)
    {
        if (K >= N - i)
        {
            K = K - (N - i);
            list[i] = end--;
        }
        else
        {
            list[i] = start++;
        }
    }

    if (K != 0)
    {
        cout << "-1";
    }
    else
    {
        for (int i = 1; i <= N; i++)
            cout << list[i] << " ";
    }
}

int main()
{
    fastIO();
    solve();
}
