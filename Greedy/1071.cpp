#include <iostream>
#include <vector>
#include <algorithm>
bool st_sort(int a, int b)
{
  return a < b;
};
void swap(std::vector<int> &data, int a, int b)
{ //a를 b로 교체
  int temp = data[a];
  data[a] = data[b];
  data[b] = temp;
}
void Sort(std::vector<int> &data)
{
  int n = data.size();
  for (int i = 0; i < n - 1; i++)
  {
    if (data[i] + 1 == data[i + 1])
    {
      int index = i + 1;
      int dindex = i;
      for (int j = i + 2; j < n; j++)
      {
        if (data[i + 1] < data[j])
        {
          index = j;
          dindex = i + 1;
          break;
        }
      }
      swap(data, dindex, index);
      if (i > 0)
        i -= 2;
    }
  }
}
int main()
{
  using namespace std;
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  vector<int> data;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> k;
    data.push_back(k);
  }
  sort(data.begin(), data.end(), st_sort);
  Sort(data);
  for (auto x : data)
    cout << x << " ";
}