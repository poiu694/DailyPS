int map[R + 1][C + 1];

// R X C Matrix - > C X R Matrix
// rotate 90
void rotate()
{
    int temp[R + 1][C + 1];

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            temp[i][j] = map[i][j];
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            map[i][j] = temp[R - 1 - j][i];
        }
    }

    swap(R, C); // R & C size Change
}