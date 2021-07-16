#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    sort(win_nums.begin(), win_nums.end());
    sort(lottos.begin(), lottos.end());

    int cnt = 0;
    int ldx = upper_bound(lottos.begin(), lottos.end(), 0) - lottos.begin();
    int zeroCnt = ldx;
    int rdx = 0;
    while (ldx != lottos.size() && rdx != win_nums.size())
    {
        if (lottos[ldx] == win_nums[rdx])
        {
            ldx++;
            rdx++;
            cnt++;
        }
        else if (lottos[ldx] > win_nums[rdx])
        {
            rdx++;
        }
        else
        {
            ldx++;
        }
    }
    vector<int> ans(2);
    if (cnt == 0 && zeroCnt == 0)
    {
        return {6, 6};
    }
    ans[1] = 7 - (cnt == 0 ? 1 : cnt);
    ans[0] = ans[1] - (cnt == 0 ? 5 : zeroCnt);
    return ans;
}