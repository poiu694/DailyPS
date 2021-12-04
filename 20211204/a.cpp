#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void    fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void    get_solution(void)
{
    string  temp;

    getline(cin, temp);
    if (temp.find("d2") != string::npos || temp.find("D2") != string::npos)
    {
        cout << "D2";
        return ;
    }
    cout << "unrated";
}

int main(void)
{
    fast_io();
    get_solution();
}

