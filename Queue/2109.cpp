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

const int INF = 987654321;

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};

void solve(){
    int N; cin >> N;
    
    priority_queue<int> pq;
    vector<pair<int, int>> v;
    int p, d;
    for (int i = 0; i < N; i++) {
        cin >> p >> d;
        v.push_back({d, p});
    }
 
    sort(v.begin(), v.end());
    
    int sum = 0;
    for(auto a : v){
        pq.push(-a.second);
        sum += a.second;
        
        if(pq.size() > a.first){
            sum += pq.top();
            pq.pop();
        }
    }
 
    cout << sum;
 
}

int main(){
  fastIO();
  solve();
}

