#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

bool isMinimality(vector<int> list, int now)
{
  for (auto key : list)
    if ((key & now) == key)
      return false;

  return true;
}

int solution(vector<vector<string>> relation)
{
  vector<int> ans;

  int rowSize = relation.size();
  int colSize = relation[0].size();

  for (int i = 1; i < (1 << colSize); i++)
  {
    set<string> s;

    for (int j = 0; j < rowSize; j++)
    {
      string sub = "";

      for (int k = 0; k < colSize; k++)
        if (i & (1 << k))
          sub += relation[j][k] + " ";

      s.insert(sub);
    }
    if (s.size() == rowSize and isMinimality(ans, i))
      ans.push_back(i);
  }

  return ans.size();
}