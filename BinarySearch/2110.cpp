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

bool isPossible(int mid, int C, vector<int> list)
{
    //    int cnt = 0;
    //    for(int i=0; i<list.size()-1; i++){
    //        if(list[i+1] - list[i] >= mid){
    //            cnt++;
    //        }
    //    }
    //    if(cnt >= C) return true;
    int cnt = 0;
    do
    {
        int tempMin = INT_MAX;
        for (int i = 0; i < C - 1; i++)
        {
            if (tempMin > abs(list[i + 1] - list[i]))
            {
                tempMin = abs(list[i + 1] - list[i]);
            }
        }
        if (tempMin <= mid)
            cnt++;
    } while (next_permutation(list.begin(), list.end()));

    if (cnt >= C)
        return true;
    return false;
}

void solve()
{
    int N, C;
    cin >> N >> C;

    vector<int> list(N);
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
    }
    sort(list.begin(), list.end());

    int start = 1;
    int end = list[N - 1] - list[0];
    int mid, cnt, now;
    int ans = -1;
    while (start <= end)
    {
        cnt = 1;
        now = list[0];
        mid = (start + end) / 2;

        for (int i = 1; i < N; i++)
        {
            if (list[i] - now >= mid)
            {
                cnt++;
                now = list[i];
            }
        }

        if (cnt >= C)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        if (ans < mid && cnt >= C)
        {
            ans = mid;
        }
    }

    cout << ans;
}

int main()
{
    fastIO();
    solve();
}
