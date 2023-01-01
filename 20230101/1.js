function solution(A, _S) {
  const S = _S[0];

  let lp = 0,
    rp = 0;
  let sum = 0;
  let answer = 0;
  for (let lp = 0; lp < A.length; lp++) {
    while (rp < A.length && sum < S) {
      sum += A[rp++];
    }
    if (sum === S) {
      answer++;
    }
    sum -= A[lp];
  }
  return [answer];
}
