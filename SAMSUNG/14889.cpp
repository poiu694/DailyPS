#include <iostream>
#include <vector>
#include <cmath>
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
    int N;
    cin >> N;

    vector<vector<int> > map(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    vector<bool> comb(N, true);
    for (int i = 0; i < (N / 2); i++)
    {
        comb[i] = false;
    }

    int ans = 987654321;
    do
    {
        int startSum = 0;
        int linkSum = 0;

        vector<int> startList;
        vector<int> linkList;
        for (int i = 0; i < N; i++)
        {
            if (comb[i])
            {
                startList.push_back(i);
            }
            else
            {
                linkList.push_back(i);
            }
        }

        for (int i = 0; i < startList.size(); i++)
        {
            int now = startList[i];
            for (int j = 0; j < startList.size(); j++)
            {
                int next = startList[j];
                startSum += map[now][next];
            }
        }

        for (int i = 0; i < linkList.size(); i++)
        {
            int now = linkList[i];
            for (int j = 0; j < linkList.size(); j++)
            {
                int next = linkList[j];
                linkSum += map[now][next];
            }
        }

        ans = min(ans, abs(startSum - linkSum));
    } while (next_permutation(comb.begin(), comb.end()));

    cout << ans;
}

int main()
{
    fastIO();
    solve();
}
