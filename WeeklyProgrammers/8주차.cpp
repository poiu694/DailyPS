#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int max_w = -1;
    int max_h = -1;
    for (int i = 0; i < sizes.size(); i++)
    {
        max_w = max(max_w, min(sizes[i][0], sizes[i][1]));
        max_h = max(max_h, max(sizes[i][0], sizes[i][1]));
    }
    return max_w * max_h;
}