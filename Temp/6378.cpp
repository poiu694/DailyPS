#include <iostream>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int stringdigitSum(string target)
{
    int sum = 0;

    for (int i = 0; i < target.length(); i++)
    {
        sum += target[i] - '0';
    }
    return sum;
}

int digitSum(int target)
{
    int sum = 0;

    while (target != 0)
    {
        sum += target % 10;
        target /= 10;
    }

    return sum;
}

void solve()
{
    while (true)
    {
        string N;
        cin >> N;

        if (N == "0")
            return;

        string target = N;
        int ans;
        while (true)
        {
            ans = stringdigitSum(target);

            while (ans >= 10)
            {
                ans = digitSum(ans);
            }
            break;
        }

        cout << ans << '\n';
    }
}

int main()
{
    fastIO();
    solve();
}
