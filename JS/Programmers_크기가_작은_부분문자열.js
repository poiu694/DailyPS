function solution(t, p) {
  const numberP = Number(p);
  const length = p.length;

  let answer = 0;
  for (let i = 0; i <= t.length - length; i++) {
    if (Number(t.substr(i, length)) <= numberP) {
      answer++;
    }
  }
  return answer;
}
