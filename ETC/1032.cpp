#include <iostream>
#include <vector>

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
    vector<string> list(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> list[i];
    }

    for (int i = 0; i < list[0].length(); i++)
    {
        char ch = list[0][i];
        for (int j = 1; j < N; j++)
        {
            if (ch != list[j][i])
            {
                ch = '?';
            }
        }
        cout << ch;
    }
}

int main()
{
    fastIO();
    solve();
}