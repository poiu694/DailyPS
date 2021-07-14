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
    int N;
    string encoded;
    vector<string> word;
    vector<string> bits;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string w, b;
        cin >> w >> b;
        word.push_back(w);
        bits.push_back(b);
    }
    cin >> encoded;

    int start = 0;
    int len = 0;
    string answer = "";
    while (start + len - 1 != encoded.length())
    {
        string temp = encoded.substr(start, len);

        bool flag = false;
        for (int i = 0; i < bits.size(); i++)
        {
            if (temp == bits[i])
            {
                flag = true;
                answer += word[i];
            }
        }

        if (flag)
        {
            start += len;
            len = 0;
        }
        else
        {
            len++;
        }
    }
    cout << answer;
}

int main()
{
    fastIO();
    solve();
}
