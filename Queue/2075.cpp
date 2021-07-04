#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
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
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> minQ;
    int temp;
    for (int i = 0; i < N * N; i++)
    {
        cin >> temp;
        if (minQ.size() < N)
        {
            minQ.push(temp);
        }
        else if (minQ.top() < temp)
        {
            minQ.pop();
            minQ.push(temp);
        }
    }

    cout << minQ.top();
}

int main()
{
    fastIO();
    solve();
}
