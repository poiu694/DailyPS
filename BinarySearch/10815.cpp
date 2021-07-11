#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> list;
vector<int> target;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input(){
    int temp;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> temp;
        list.push_back(temp);
    }

    cin >> M;
    for(int i=0; i<M; i++){
        cin >> temp;
        target.push_back(temp);
    }
}

void binarySearch(int start, int end, int num){
    if(start > end){
        cout << "0 ";
    }else{
        int mid = (start + end) / 2;

        if(list[mid] == num){
            cout << "1 ";
        }else if(list[mid] > num){
            return binarySearch(start, mid-1, num);
        }else{
            return binarySearch(mid+1, end, num);
        }
    }
}

void solve(){
    sort(list.begin(), list.end());

    for(int i=0; i<M; i++){
        binarySearch(0, N-1, target[i]);
    }
}

int main(){
    init();
    input();
    solve();
}