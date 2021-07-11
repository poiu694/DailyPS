#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
vector<int> findNum;

void init(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

void input(){
	int num;
	
	cin >> N;
    for(int i=0; i<N; i++){
        cin >> num;
        arr.push_back(num);
    }

    cin >> M;
    for(int i=0; i<M; i++){
        cin >> num;
        findNum.push_back(num);
    }
}

void binarySearch(int start, int end, int target){
    // target이 없을 때
    if(start > end){
       cout << "0\n";
    }
    else{
        int mid = (start + end) / 2;

        if(arr[mid] > target){
            return binarySearch(start, mid-1, target);
        }else if(arr[mid] < target){
            return binarySearch(mid+1, end, target);
        }else{
            cout << "1\n";
        }
    }
    
}

void solve(){
    sort(arr.begin(), arr.end());

    for(int i=0; i<M; i++){
        binarySearch(0, N-1, findNum[i]);
    }
}

int main(){
	init();
    input();
    solve();
}