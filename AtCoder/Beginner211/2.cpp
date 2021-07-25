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
    cout.precision(5);
    cout << fixed;
}

void solve()
{
    string s[4];
    cin >> s[0] >> s[1] >> s[2] >> s[3];

    bool visited[4];
    memset(visited, false, sizeof(visited));

    for (string target : s)
    {
        if (target == "H")
            visited[0] = true;
        else if (target == "2B")
            visited[1] = true;
        else if (target == "3B")
            visited[2] = true;
        else if (target == "HR")
            visited[3] = true;
    }

    bool flag = true;
    for (int i = 0; i < 4; i++)
    {
        if (!visited[i])
            flag = false;
    }
    if (flag)
        cout << "Yes";
    else
        cout << "No";
}

int main()
{
    fastIO();
    solve();
}
