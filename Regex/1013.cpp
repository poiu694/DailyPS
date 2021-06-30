#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <regex>
#include <cstring>

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

    while (N--)
    {
        string target;
        cin >> target;

        regex re("(100+1+|01)+");

        if (regex_match(target, re))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}

int main()
{
    fastIO();
    solve();
}
