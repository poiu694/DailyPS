#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
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
    string target;
    cin >> target;

    if (target == "0")
    {
        cout << "W";
        return;
    }

    int xIndex = -1;
    for (int i = 0; i < target.length(); i++)
    {
        if (target[i] == 'x')
        {
            xIndex = i;
            break;
        }
    }
    if (xIndex == -1)
    {
        target = (target == "1") ? "" : (target == "-1") ? "-"
                                                         : target;
        cout << target + "x+W";
        return;
    }

    string coefficent1 = to_string(stoi(target.substr(0, xIndex)) / 2);
    coefficent1 = (coefficent1 == "1") ? "" : (coefficent1 == "-1") ? "-"
                                                                    : coefficent1;
    string coefficent2 = target.substr(xIndex + 1, target.length() - xIndex - 1);
    cout << coefficent1 + "xx";
    if (coefficent2 == "")
    {
        cout << "+W";
        return;
    }
    coefficent2 = (coefficent2 == "+1") ? "+" : (coefficent2 == "-1") ? "-"
                                                                      : coefficent2;
    cout << coefficent2 + "x" + "+W";
}

int main()
{
    fastIO();
    solve();
}
