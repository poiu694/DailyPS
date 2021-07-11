#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int N, M;
    cin >> N >> M;

    vector<int> list(N);
    int mx = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
        if (mx < list[i])
            mx = list[i];
    }

    long start = 0;
    long end = mx;
    long cut = (start + end) / 2;
    while (true)
    {
        if (start == cut)
        {
            break;
        }

        long amount = 0;

        for (int i = 0; i < N; i++)
        {
            if (cut >= list[i])
            {
                continue;
            }
            else
            {
                amount += list[i] - cut;
            }
        }
        if (amount == M)
        {
            break;
        }
        else if (amount < M)
        {
            end = cut;
            cut = (start + end) / 2;
        }
        else
        {
            start = cut;
            cut = (start + end) / 2;
        }
    }
    cout << cut;
}

int main()
{
    fastIO();
    solve();
}
