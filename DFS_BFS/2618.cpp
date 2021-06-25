#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    int N, W;
    cin >> N >> W;

    pair<int, int> police1 = {1, 1};
    pair<int, int> police2 = {N, N};
    vector<int> list;

    int sum = 0;
    int x, y;
    for(int i=0; i<W; i++){
        cin >> x >> y;
        
        int dist1 = abs(x - police1.first) + abs(y-police1.second);
        int dist2 = abs(y - police2.first) + abs(y - police2.second);

        if(dist1 > dist2){
            sum += dist2;
            police2.first = x;
            police2.second = y;
            list.push_back(2);  
        }else{
            sum += dist1;
            police1.first = x;
            police1.second = y;
            list.push_back(1);
        }
    }

    cout << sum << '\n';
    for(int i=0; i<list.size(); i++){
        cout << list[i] << '\n';
    }
}

int main(){
    fastIO();
    solve();
}