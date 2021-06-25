#include <iostream>
#include <cmath>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve()
{
    int atk[4], power[4], crit[4], critPower[4], atkSpeed[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> atk[i] >> power[i] >> crit[i] >> critPower[i] >> atkSpeed[i];
    }

    int kingPower[4];
    for (int i = 0; i < 4; i++)
    {
        kingPower[i] = (atk[i]) * (1 + (power[i] / 100)) *
                           (1 - min(crit[i] / 100, 1)) +
                       (min(crit[i] / 100, 1) * (critPower[i] / 100)) *
                           (1 + (atkSpeed[1] / 100));
    }

    if (kingPower[0])
}

int main()
{
    fastIO();
    solve();
}