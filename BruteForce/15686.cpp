#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
int map[51][51];

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    cin >> N >> M;

    vector<pair<int, int>> markets;
    vector<pair<int, int>> homes;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                markets.push_back({i, j});
            }
            else if (map[i][j] == 1)
            {
                homes.push_back({i, j});
            }
        }
    }

    int ans = 987654321;
    for (int i = 1; i <= M; i++)
    {
        vector<bool> isActiveMarket(markets.size(), false);
        for (int j = 0; j < i; j++)
            isActiveMarket[j] = true;
        do
        {
            vector<pair<int, int>> validMarkets;
            for (int j = 0; j < isActiveMarket.size(); j++)
            {
                if (isActiveMarket[j])
                {
                    validMarkets.push_back({markets[j].first, markets[j].second});
                }
            }

            int sum = 0;
            for (auto home : homes)
            {
                int minDist = 987654321;
                for (auto market : validMarkets)
                {
                    if (minDist > abs(market.first - home.first) + abs(market.second - home.second))
                    {
                        minDist = abs(market.first - home.first) + abs(market.second - home.second);
                    }
                }
                sum += minDist;
            }

            if (ans > sum)
                ans = sum;
        } while (prev_permutation(isActiveMarket.begin(), isActiveMarket.end()));
    }
    cout << ans;
}

int main()
{
    fastIO();
    solve();
}
