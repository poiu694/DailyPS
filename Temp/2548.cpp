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
    int N;
    cin >> N;

    vector<int> list(N);
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
    }

    sort(list.begin(), list.end());

    cout << list[(list.size() - 1) / 2];
}

int main()
{
    fastIO();
    solve();
}
