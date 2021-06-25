#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<int> list;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void change(int target, int num){
    for(int i=0; i<list.size(); i++){
        if(list[i] == target){
            list[i] = num;
            break;
        }
    }
}

void multi(int start, int end){
    int mul = list[start-1];

    for(int i=start; i<end; i++){
        mul *= list[i];
    }

    cout << mul << '\n';
}

void solve(){
    cin >> N >> M >> K;
    
    int temp;
    for(int i=0; i<N; i++){
        cin >> temp;
        list.push_back(temp);
    }

    int a, b, c;
    for(int i=0; i<M+K; i++){
        cin >> a >> b >> c;

        if(a == 1){
            change(b,c);
        }else{
            multi(b,c);
        }
    }
}

int main(){
    init();
    solve();
}