#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int num, int cnt, int k, int start, int temp, int end){
	if(cnt==k){
		cout << start << '\n';
	}else{
		hanoi(num-1,cnt +1, k, start, end, temp);
		cout << start << " " << end << '\n';
		hanoi(num-1,cnt + 1, k, temp, start, end);
	}
}

int main() {
	int N = 32;

	cout << (1<<N) -1 << '\n';
	hanoi(N, 0, 5, 1,2,3);
}
