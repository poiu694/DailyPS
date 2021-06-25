#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int N, S, M;		
using namespace std;
priority_queue<pair<int, int> > pq; // maxQ, time&who
vector<int> timeList;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void input() {
	cin >> N >> S >> M;

	int temp;
	for (int i = 1; i <= M; i++) {
		cin >> temp;
		timeList.push_back(temp);
		pq.push({ 0, -i }); // minQ로 만들어 주기 위해 -
	}
}

void solve() {
	int cnt = 0;
	int time, who;
	while (true)
	{
		// pq는 time이 제일 작은 것부터, 그리고 people이 작은 것부터 출력
		// 3이 3초에 먹고나서는 8초'부터' 먹을 수 있다
		// 8초에 들어간 숫자는 1과 3이 있는데 1이 우선순위 임으로 1부터 출력

		// 종료 조건
		if (cnt >= N - S) {
			cout << who;
			break;
		}

		// time, who in pq is < 0
		time = -pq.top().first; // Enter time
		who = -pq.top().second; // Enter People
		pq.pop();

		pq.push({ -(time + timeList[who -1]), -who }); // - is for MinQ
		
		cnt++;
	}
}

int main() {
	init();
	input();
	solve();
}