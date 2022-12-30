function bfs(a, b, c, d) {
  const q = [];

  q.push([a, b]);
  while (q.length !== 0) {
    const [currentA, currentB] = q.pop();
    if (currentA === c && currentB === d) {
      return 'Yes';
    }
    if (currentA + currentB <= c) {
      q.push([currentA + currentB, currentB]);
    }
    if (currentA + currentB <= d) {
      q.push([currentA, currentA + currentB]);
    }
  }
  return 'No';
}

function solution(arr) {
  const a = arr[0];
  const b = arr[1];
  const c = arr[2];
  const d = arr[3];

  return bfs(a, b, c, d);
}
