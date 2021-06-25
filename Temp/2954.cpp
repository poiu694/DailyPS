#include <iostream>
#include <queue>

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
    priority_queue<int> pq;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    int ans = -1;
    int day = 1;
    while (!pq.empty())
    {
        int now = pq.top();
        pq.pop();

        ans = ans > now + day ? ans : now + day;
        day++;
    }

    cout << ans + 1;
}

int main()
{
    fastIO();
    solve();
}
