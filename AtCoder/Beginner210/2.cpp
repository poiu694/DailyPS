#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
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
    int N;
    string s;
    cin >> N >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            if (i % 2 == 0)
                cout << "Takahashi";
            else
                cout << "Aoki";
            break;
        }
    }
}

int main()
{
    fastIO();
    solve();
}
