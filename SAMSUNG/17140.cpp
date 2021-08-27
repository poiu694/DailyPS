#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

const int MAX_TIME = 100;
int board[101][101];

void fastIO()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
  if (a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}

void solve()
{
  int r, c, k;
  cin >> r >> c >> k;

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      cin >> board[i][j];

  int rowSize = 3;
  int colSize = 3;
  int time = 0;
  while (time <= MAX_TIME)
  {
    // End Condition
    if (board[r - 1][c - 1] == k)
      break;

    // Temp List
    vector<pair<int, int>> list;
    map<int, int> m;

    // Operation
    // do R
    if (rowSize >= colSize)
    {
      int maxSize = -1;
      for (int i = 0; i < rowSize; i++)
      {
        for (int j = 0; j < colSize; j++)
        {
          if (board[i][j] == 0)
            continue;
          m[board[i][j]]++;
          board[i][j] = 0;
        }

        copy(m.begin(), m.end(), back_inserter<vector<pair<int, int>>>(list));
        sort(list.begin(), list.end(), cmp);

        int idx = 0;
        for (auto s : list)
        {
          if (idx > 99)
            break;
          board[i][idx++] = s.first;
          board[i][idx++] = s.second;
        }

        if (maxSize < (int)list.size() * 2)
          maxSize = (int)list.size() * 2;

        m.clear();
        list.clear();
      }
      colSize = maxSize;
    }
    // do C
    else
    {
      int maxSize = -1;
      for (int i = 0; i < colSize; i++)
      {
        for (int j = 0; j < rowSize; j++)
        {
          if (board[j][i] == 0)
            continue;
          m[board[j][i]]++;
          board[j][i] = 0;
        }

        copy(m.begin(), m.end(), back_inserter<vector<pair<int, int>>>(list));
        sort(list.begin(), list.end(), cmp);

        int idx = 0;
        for (auto s : list)
        {
          if (idx > 99)
            break;
          board[idx++][i] = s.first;
          board[idx++][i] = s.second;
        }

        if (maxSize < (int)list.size() * 2)
          maxSize = (int)list.size() * 2;

        m.clear();
        list.clear();
      }
      rowSize = maxSize;
    }

    time++;
  }

  if (time <= MAX_TIME)
    cout << time;
  else
    cout << -1;
}

int main()
{
  fastIO();
  solve();
}
