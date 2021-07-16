#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <limits.h>

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
    cin >> N;

    vector<int> list(N);
    for (int i = 0; i < N; i++)
        cin >> list[i];
    cin >> M;

    sort(list.begin(), list.end());
    int start = 1;
    int end = M;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        int sum = 0;
        for (int i = 0; i < list.size(); i++)
        {
            if (mid < list[i])
                sum += mid;
            else
                sum += list[i];
        }
        if (sum < M)
        {
            start = mid + 1;
        }
        else if (sum > M)
        {
            end = mid - 1;
        }
        else
        {
            end = mid;
            break;
        }
    }
    if (end > list[N - 1])
        end = list[N - 1];
    cout << end;
}

int main()
{
    fastIO();
    solve();
}
