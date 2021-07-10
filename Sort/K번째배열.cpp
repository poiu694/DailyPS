#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k)
{
    vector<int> list(n);
    for (int i = 0; i < n; i++)
        list[i] = i + 1;
    long long cnt = 0;
    vector<int> answer;
    do
    {
        cnt++;
        if (cnt == k)
        {
            answer = list;
            break;
        }
    } while (next_permutation(list.begin(), list.end()));

    return answer;
}