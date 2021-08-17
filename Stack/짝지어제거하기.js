function solution(s)
{
    const st = [];
    s.split('').forEach((v) => {
        if (st.length > 0 && v === st[st.length - 1])
            st.pop();
        else
            st.push(v);
    });
    return st.length === 0 ? 1 : 0;
}