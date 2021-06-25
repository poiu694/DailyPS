#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long long> list;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    cin >> N;
}

void solve(){
    for(int i=1; i<10; i++){
        list.push_back(i);
    }

    while(N--){
        for(int i=0; i<list.size(); i++){
            if(list[i] % 10 == 9){
                
            }else if (list[i] % 10 == 0)){

            }
        }
    }
}

int main(){
    init();
    input();
    solve();
}