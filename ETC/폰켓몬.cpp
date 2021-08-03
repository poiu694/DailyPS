#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    map<int, int> m;
    for (int num : nums)
    {
        m[num]++;
    }

    int nSize = nums.size();
    int mSize = m.size();
    int answer = -1;
    if (mSize >= nSize / 2)
        answer = nSize / 2;
    else
        answer = mSize;
    return answer;
}