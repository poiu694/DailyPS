#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int a[4000001];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> primeList(int N)
{
    vector<int> list;

    memset(a, -1, sizeof(a));
    for (int i = 2; i <= N; i++)
    {
        if (a[i] == 0)
            continue;
        for (int j = i + i; j <= N; j += i)
        {
            a[j] = 0;
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (a[i] == -1)
            list.push_back(i);
    }

    return list;
}

void solve()
{
    int N;
    cin >> N;

    vector<int> list = primeList(N);

    int l = 0;
    int r = 0;
    int cnt = 0;
    while (r != list.size())
    {
        int sum = 0;

        for (int i = l; i <= r; i++)
        {
            sum += list[i];
        }
        if (sum == N)
        {
            cnt++;
            l = l + 1;
        }
        else if (sum < N)
        {
            r = r + 1;
        }
        else if (sum > N)
        {
            l = l + 1;
        }
    }

    cout << cnt;
}

int main()
{
    fastIO();
    solve();
}
