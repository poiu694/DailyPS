
int log2n(int n)
{
    int last = -1;
    for (int i = 0; i < 30; ++i)
    {
        if (((n >> i) & 1) == 1)
        {
            last = i;
        }
    }
    return last;
}
int log2n(int n)
{
    int cnt = 0;
    while (n != 0)
    {
        cnt++;
        n = n / 2;
    }
    return cnt;
}
