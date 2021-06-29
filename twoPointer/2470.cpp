#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve(){
    int N;
    cin >> N;
    
    vector<int> list(N);
    for(int i=0; i<N; i++){
        cin >> list[i];
    }
    sort(list.begin(), list.end());
    
    int start = 0;
    int end = N-1;
    
    int minStart = -1;
    int minEnd = -1;
    
    int minSum = 2000000001;
    int sum;
    while(start != end){
        sum = list[start] + list[end];
        
        if(sum < 0){
            if(minSum > abs(sum)){
                minSum = abs(sum);
                minStart = start;
                minEnd = end;
            }else{
                start = start + 1;
            }
        }else if(sum > 0){
            if(minSum > abs(sum)){
                minSum = abs(sum);
                minStart = start;
                minEnd = end;
            }else{
                end = end - 1;
            }
        }else if(sum == 0){
            minStart = start;
            minEnd = end;
            break;
        }
    }
    
    cout << list[minStart] << " " << list[minEnd];
}

int main(){
    fastIO();
    solve();
}
