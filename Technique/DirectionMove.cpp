int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // Direction (N-E-S-W)

const int WALL = 2;
const int SIZE = 1;
int N, M;
int map[101][101];

// 끝까지 가는 Move
void updateMap(int x, int y, int dir)
{
    dir = dir % 4; // 네가지 방향ㅇ
    while (true)
    {
        x = x + dx[dir];
        y = y + dy[dir];

        if (x < 0 || y < 0 || x >= N || y >= M || map[x][y] == WALL)
        {
            return;
        }
    }
}

void bruteForce()
{
    // 4진법으로 4가지 방향 완전탐색
    // 0 : N, 1 : E, 2 : S, 3 : W
    for (int brute = 0; brute < (1 << (2 * SIZE)); brute++)
    {

        int temp = brute;
        for (int i = 0; i < SIZE; i++)
        {
            int dir = temp % 4;
            temp /= 4;

            int x = 1; // 특정 행위를 시작하는 좌표
            int y = 1;
            updateMap(x, y, dir); // 이 방향으로 끝까지 움직여라
        }
    }
}