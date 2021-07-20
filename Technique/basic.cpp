#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <limits.h>

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  
  cout << A*B + (N-A)*C;
}

int main(){
  fastIO();
  solve();
}
