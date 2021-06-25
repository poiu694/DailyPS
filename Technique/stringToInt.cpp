stack<int> st;

for (int i = 1; i < target.length(); i++)
{ // 맨 처음은 '['이라 생략
    if ('0' <= target[i] && target[i] <= '9')
    {
        st.push(target[i] - '0');
    }
    else
    {
        int sum = 0, p = 0;

        while (!st.empty())
        {
            sum += st.top() * pow(10, p);
            st.pop();
            p++;
        }
        dq.push_back(sum);
    }
}