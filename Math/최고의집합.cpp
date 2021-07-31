#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, int s)
{
    vector<int> list;
    if (s < n)
        list.push_back(-1);
    else if (s % n == 0)
    {
        for (int i = 0; i < n; i++)
            list.push_back(s / n);
    }
    else
    { // s % n != 0
        int ret = s % n;
        for (int i = 0; i < n; i++)
            list.push_back(s / n);
        for (int i = n - 1; i >= 0; i--)
        {
            if (ret > 0)
            {
                list[i]++;
                ret--;
            }
            else if (ret == 0)
                break;
        }
    }
    return list;
}