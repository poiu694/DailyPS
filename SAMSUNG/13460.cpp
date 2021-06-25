#include <iostream>
#include <queue>
using namespace std;

struct ballinfo {
	int rx, ry, bx, by, cnt; //돌린 개수
};

int n, m;
int ans = 11; //최솟값 비교해야함
int map[10][10];
bool check[10][10][10][10];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int rx, ry;
int bx, by;

queue<ballinfo> q; //red ball, blue ball


void solve() {

	while (!q.empty()) {

		ballinfo ball = q.front();
		q.pop();

		//한 번 dx, dy갈때 무조건 벽에 닿일때까지 가야함
		for (int i = 0; i < 4; i++) {
			//if (map[ball.rx + dx[i]][ball.ry + dy[i]] >= 0) {

				//이만큼 굴리고 q에 넣음
				int redcount = 0;
				int bluecount = 0;
				int subrx = ball.rx;
				int subry = ball.ry;
				int subbx = ball.bx;
				int subby = ball.by;
				
				//red ball
				while (map[subrx][subry]!= 100 && map[subrx][subry] != -1) {
					subrx += dx[i];
					subry += dy[i];
					redcount++;
				}

				// 'O' 거나 '#'이 되면 나옴

				//blue ball
				while (map[subbx][subby] != 100 && map[subbx][subby] != -1) {
					subbx += dx[i];
					subby += dy[i];
					bluecount++;
				}

				//blue가 O인경우
				if (map[subbx][subby] == 100)
					continue;

				//red가 O인경우
				if (map[subrx][subry] == 100) {
					if (ball.cnt + 1 < ans){
						ans = ball.cnt + 1;
						}
					break; //bfs 더 진행 안해도 됨. 여기서 bfs 더 진행해봤자 이거보다 많은 count이므로
				}

				//그냥 둘 다 빈칸인 경우

				if (subrx == subbx && subry == subby) {
					//count 비교
					if (redcount < bluecount) {
						subbx -= dx[i];
						subby -= dy[i];
					}
					else {
						subrx -= dx[i];
						subry -= dy[i];
					}
				}

				subrx -= dx[i];
				subry -= dy[i];
				subbx -= dx[i];
				subby -= dy[i];

				if (check[subrx][subry][subbx][subby]) //check!!! 중복 안되게!!!
					continue;

				q.push({ subrx,subry,subbx,subby,ball.cnt + 1 });
				check[subrx][subry][subbx][subby] = true;

		}

	}

}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			
			switch (c) {
			case '#':
				map[i][j] = -1; break;
			case '.':
				map[i][j] = 0; break;
			case 'O':
				map[i][j] = 100; break;
			case 'R':
				rx = i; ry = j; break;
			case 'B':
				bx = i; by = j; break;
			}
		}
	}

	q.push({ rx, ry, bx, by, 0 }); //{}로 넣어줘야함
	check[rx][ry][bx][by] = true; //bfs는 무조건~~
	solve();

	if (ans > 10)
		ans = -1;

	cout << ans << "\n";

	return 0;
}

/*
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;


struct lc {
    int rx;
    int ry;
    int bx;
    int by;
    int cnt;

    lc(int _rx, int _ry, int _bx, int _by, int _cnt) {
        rx = _rx;
        ry = _ry;
        bx = _bx;
        by = _by;
        cnt = _cnt;
    }
};

int N, M;
int redX, redY; // red
int blueX, blueY; // blue
char map[11][11];
char _map[11][11];
bool visited[11][11][11][11];
queue<lc> q;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input() {
    cin >> N >> M;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < M; j++) {
            map[i][j] = str[j];
            if (map[i][j] == 'R') {
                redX = i;
                redY = j;
            }
            else if (map[i][j] == 'B') {
                blueX = i;
                blueY = j;
            }
        }
    }
}

void copyMap(int a, int b, int c, int d) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            _map[i][j] = map[i][j];
        }
    }
    _map[redX][redY] = '.'; _map[blueX][blueY] = '.';
    _map[a][b] = 'R'; _map[c][d] = 'B';
}

void solve() {
    int minCnt = 987654321;

    q.push(lc(redX, redY, blueX, blueY, 0));

    while (!q.empty()) {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int _cnt = q.front().cnt;
        q.pop();

        if (visited[rx][ry][bx][by]) {
            continue;
        }

        visited[rx][ry][bx][by] = true;

        // Left
        // Blue가 더 오른쪽에 있으면? red부터 움직이고 blue를 움직인다.
        int _rx = rx; int _ry = ry; int _bx = bx; int _by = by;
        bool redFlag = false; bool blueFlag = false;
        copyMap(rx, ry, bx, by);
        if (_ry < _by) {
            _map[_rx][_ry] = '.';
            while (true) {
                if (_ry > 0 && _map[_rx][--_ry] == '.') {

                }
                else if (_map[_rx][_ry] == 'O') {
                    redFlag = true;
                    break;
                }
                else if (_map[_rx][_ry] == '#') {
                    _ry++;
                    break;
                }
                else if (_ry == 0) break;
            }
            if (!redFlag) {
                _map[_rx][_ry] = 'R';
            }

            while (true) {
                _map[_bx][_by] = '.';
                if (_map[_bx][--_by] == '.' && _by > 0) {

                }
                else if (_map[_bx][_by] == 'O') {
                    blueFlag = true;
                    break;
                }
                else if (_map[_bx][_by] == 'R' || _map[_bx][_by] == '#') {
                    _by++;
                    break;
                }
                else if (_by == 0) {
                    break;
                }
            }

            if (redFlag && !blueFlag) { 
                minCnt = _cnt + 1;
                break;
            }
            else if (_map[_bx][_by] == '.' && _map[_rx][_ry] == 'R') {
                if (rx != _rx || ry != _ry || bx != _bx || by != _by) {
                    q.push(lc(_rx, _ry, _bx, _by, _cnt + 1));
                }
            }
        }
        // red - blue
        else {
            while (true) {
                _map[_bx][_by] = '.';
                if (_map[_bx][--_by] == '.' && _by > 0) {

                }
                else if (_map[_bx][_by] == 'O') {
                    blueFlag = true;
                    break;
                }
                else if (_map[_bx][_by] == '#') {
                    _by++;
                    break;
                }
                else if (_by == 0)break;
            }
            if (_map[_bx][_by] != 'O') {
                _map[_bx][_by] = 'B';
            }
            

            while (true) {
                _map[_rx][_ry] = '.';
                if (_map[_rx][--_ry] == '.' && _ry > 0) {

                }
                else if (_map[_rx][_ry] == 'O') {
                    redFlag = true;
                    break;
                }
                else if (_map[_rx][_ry] == 'B' || _map[_rx][_ry] == '#') {
                    _ry++;
                    break;
                }
                else if (_ry == 0) break;
            }
            if (redFlag && !blueFlag) {
                minCnt = _cnt + 1;
                break;
            }
            else if (_map[_bx][_by] == 'B' && _map[_rx][_ry] == '.') {
                if (rx != _rx || ry != _ry || bx != _bx || by != _by) {
                    q.push(lc(_rx, _ry, _bx, _by, _cnt + 1));
                }
            }
        }

        // right
        _rx = rx; _ry = ry; _bx = bx; _by = by;
        redFlag = false; blueFlag = false;
        copyMap(rx, ry, bx, by);
        if (_ry < _by) {
            while (true) {
                _map[_bx][_by] = '.';
                if (_map[_bx][++_by] == '.' && _by < M - 1) {
                }
                else if (_map[_bx][_by] == 'O') {
                    blueFlag = true;
                    break;
                }
                else if (_map[_bx][_by] == '#') {
                    _by--;
                    break;
                }
                else if (_by == M - 1)break;
            }
            if (_map[_bx][_by] != 'O') {
                _map[_bx][_by] = 'B';
            }
            while (true) {
                _map[_rx][_ry] = '.';
                if (_map[_rx][++_ry] == '.' && _ry < M - 1) {
                }
                else if (_map[_rx][_ry] == 'O') {
                    redFlag = true;
                    break;
                }
                else if (_map[_rx][_ry] == 'B' || _map[_rx][_ry] == '#') {
                    _ry--;
                    break;
                }
                else if (_ry == M - 1) break;
            }

            if (redFlag && !blueFlag) {
                minCnt = _cnt + 1;
                break;
            }
            else if (_map[_bx][_by] == 'B' && _map[_rx][_ry] == '.') {
                if (rx != _rx || ry != _ry || bx != _bx || by != _by) {
                    q.push(lc(_rx, _ry, _bx, _by, _cnt + 1));
                }
            }
        }
        // red - blue
        else {
            while (true) {
                _map[_rx][_ry] = '.';
                if (_map[_rx][++_ry] == '.' && _ry < M - 1) {

                }
                else if (_map[_rx][_ry] == 'O') {
                    redFlag = true;
                    break;
                }
                else if (_map[_rx][_ry] == '#') {
                    _ry--;
                    break;
                }
                else if (_ry == M - 1) break;
            }
            if (!redFlag) {
                _map[_rx][_ry] = 'R';
            }

            while (true) {
                _map[_bx][_by] = '.';
                if (_map[_bx][++_by] == '.' && _by < M - 1) {

                }
                else if (_map[_bx][_by] == 'O') {
                    blueFlag = true;
                    break;
                }
                else if (_map[_bx][_by] == 'R' || _map[_bx][_by] == '#') {
                    _by--;
                    break;
                }
                else if (_by == M - 1)break;
            }

            if (redFlag && !blueFlag) {
                minCnt = _cnt + 1;
                break;
            }
            else if (_map[_bx][_by] == '.' && _map[_rx][_ry] == 'R') {
                if (rx != _rx || ry != _ry || bx != _bx || by != _by) {
                    q.push(lc(_rx, _ry, _bx, _by, _cnt + 1));
                }
            }
        }

        // Down
        _rx = rx; _ry = ry; _bx = bx; _by = by;
        redFlag = false; blueFlag = false;
        copyMap(rx, ry, bx, by);
        if (_rx < _bx) {
            while (true) {
                _map[_bx][_by] = '.';
                if (_map[++_bx][_by] == '.' && _bx < N - 1) {

                }
                else if (_map[_bx][_by] == 'O') {
                    blueFlag = true;
                    break;
                }
                else if (_map[_bx][_by] == '#') {
                    _bx--;
                    break;
                }
                else if (_bx == N - 1)break;
            }
            if (_map[_bx][_by] != 'O') {
                _map[_bx][_by] = 'B';
            }

            while (true) {
                _map[_rx][_ry] = '.';
                if (_map[++_rx][_ry] == '.' && _rx < N - 1) {

                }
                else if (_map[_rx][_ry] == 'O') {
                    redFlag = true;
                    break;
                }
                else if (_map[_rx][_ry] == 'B' || _map[_rx][_ry] == '#') {
                    _rx--;
                    break;
                }
                else if (_rx == N - 1) break;
            }
            if (redFlag && !blueFlag) {
                minCnt = _cnt + 1;
                break;
            }
            else if (_map[_bx][_by] == 'B' && _map[_rx][_ry] == '.') {
                if (rx != _rx || ry != _ry || bx != _bx || by != _by) {
                    q.push(lc(_rx, _ry, _bx, _by, _cnt + 1));
                }
            }
        }
        // red - blue
        else {
            while (true) {
                _map[_rx][_ry] = '.';
                if (_map[++_rx][_ry] == '.' && _rx < N - 1) {

                }
                else if (_map[_rx][_ry] == 'O') {
                    redFlag = true;
                    break;
                }
                else if (_map[_rx][_ry] == '#') {
                    _rx--;
                    break;
                }
                else if (_rx == N - 1) break;
            }
            if (!redFlag) {
                _map[_rx][_ry] = 'R';
            }

            while (true) {
                _map[_bx][_by] = '.';
                if (_map[++_bx][_by] == '.' && _bx < N - 1) {

                }
                else if (_map[_bx][_by] == 'O') {
                    blueFlag = true;
                    break;
                }
                else if (_map[_bx][_by] == 'R' || _map[_bx][_by] == '#') {
                    _bx--;
                    break;
                }
                else if (_bx == N - 1)break;
            }

            if (redFlag && !blueFlag) {
                minCnt = _cnt + 1;
                break;
            }
            else if (_map[_bx][_by] == '.' && _map[_rx][_ry] == 'R') {
                if (rx != _rx || ry != _ry || bx != _bx || by != _by) {
                    q.push(lc(_rx, _ry, _bx, _by, _cnt + 1));
                }
            }
        }

        // Up
        _rx = rx; _ry = ry; _bx = bx; _by = by;
        redFlag = false; blueFlag = false;
        copyMap(rx, ry, bx, by);
        if (_rx > _bx) {
            while (true) {
                _map[_bx][_by] = '.';
                if (_map[--_bx][_by] == '.' && _bx > 0) {

                }
                else if (_map[_bx][_by] == 'O') {
                    blueFlag = true;
                    break;
                }
                else if (_map[_bx][_by] == '#') {
                    _bx++;
                    break;
                }
                else if (_bx == 0)break;
            }
            if (_map[_bx][_by] != 'O') {
                _map[_bx][_by] = 'B';
            }

            while (true) {
                _map[_rx][_ry] = '.';
                if (_map[--_rx][_ry] == '.' && _rx > 0) {

                }
                else if (_map[_rx][_ry] == 'O') {
                    redFlag = true;
                    break;
                }
                else if (_map[_rx][_ry] == 'B' || _map[_rx][_ry] == '#') {
                    _rx++;
                    break;
                }
                else if (_rx == 0) break;
            }
            if (redFlag && !blueFlag) {
                minCnt = _cnt + 1;
                break;
            }
            else if (_map[_bx][_by] == 'B' && _map[_rx][_ry] == '.') {
                if (rx != _rx || ry != _ry || bx != _bx || by != _by) {
                    q.push(lc(_rx, _ry, _bx, _by, _cnt + 1));
                }
            }
        }
        // red - blue
        else {
            while (true) {
                _map[_rx][_ry] = '.';
                if (_map[--_rx][_ry] == '.' && _rx > 0) {

                }
                else if (_map[_rx][_ry] == 'O') {
                    redFlag = true;
                    break;
                }
                else if (_map[_rx][_ry] == '#') {
                    _rx++;
                    break;
                }
                else if (_rx == 0) break;
            }
            if (!redFlag) {
                _map[_rx][_ry] = 'R';
            }

            while (true) {
                _map[_bx][_by] = '.';
                if (_map[--_bx][_by] == '.' && _bx > 0) {

                }
                else if (_map[_bx][_by] == 'O') {
                    blueFlag = true;
                    break;
                }
                else if (_map[_bx][_by] == 'R' || _map[_bx][_by] == '#') {
                    _bx++;
                    break;
                }
                else if (_bx == 0)break;
            }

            if (redFlag && !blueFlag) {
                minCnt = _cnt + 1;
                break;
            }
            else if (_map[_bx][_by] == '.' && _map[_rx][_ry] == 'R') {
                if (rx != _rx || ry != _ry || bx != _bx || by != _by) {
                    q.push(lc(_rx, _ry, _bx, _by, _cnt + 1));
                }
            }
        }
    }

    if (minCnt == 987654321 || minCnt > 10) {
        minCnt = -1;
    }
    cout << minCnt;
}

int main() {
    init();
    input();
    solve();
}*/ 