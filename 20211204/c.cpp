#include <iostream>
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

bool    is_palindrome(string str)
{
    size_t  len;

    len = str.length();
    for (int i=0; i<len / 2; i++)
    {
        if (str[i] != str[(len / 2) - 1 - i])
            return (false);
        if (str[(len / 2) + 1] != str[len - 1])
            return (false);
    }
    return (true);
}

void    get_solution(void)
{
    string  target;

    cin >> target;
    if (is_palindrome(target))
        cout << "AKARAKA";
    else
        cout << "IPSELENTI";
}

int main(void)
{
    fast_io();
    get_solution();
}
