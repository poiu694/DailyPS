#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems)
{
    map<string, int> m;
    for (string gem : gems)
    {
        m[gem]++;
    }
    int gemSize = m.size();
    m.clear();

    int start = 0;
    int end = 0;
    int minDist = 1e6 + 2;
    vector<int> answer(2);
    while (true)
    {
        if (m.size() == gemSize)
        {
            if (minDist > end - start)
            {
                minDist = end - start;
                answer[0] = start + 1;
                answer[1] = end;
            }

            if (m[gems[start]] == 1)
            {
                m.erase(gems[start++]);
            }
            else
            {
                m[gems[start++]]--;
            }
        }
        else if (end == gems.size())
        {
            break;
        }
        else
        {
            m[gems[end++]]++;
        }
    }

    return answer;
}