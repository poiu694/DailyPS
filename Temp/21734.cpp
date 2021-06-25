#include <iostream>

using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int digitSum(int num){
    int sum = 0;
    
    while(num != 0){
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

void solve(){
    string target;
    cin >> target;

    
    for(int i=0; i<target.length(); i++){
        for(int j=0; j<digitSum(target[i]); j++){
            cout << target[i];
        }
        cout << '\n';
    }
}

int main(){
    fastIO();
    solve();
}