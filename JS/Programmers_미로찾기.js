const CELL = {
  wall: 'X',
  goal: 'E',
  path: 'O',
  lever: 'L',
  start: 'S',
};

function createArray(length) {
  const arr = new Array(length || 0);
  let i = length;

  if (arguments.length > 1) {
    const args = Array.prototype.slice.call(arguments, 1);
    while (i--) arr[length - 1 - i] = createArray.apply(this, args);
  }

  return arr;
}

function findStartPosition(maps, n, m) {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (maps[i][j] === CELL.start) {
        return { startX: i, startY: j };
      }
    }
  }
  return null;
}

function bfs(maps, n, m) {
  const q = [];
  const dx = [1, 0, -1, 0];
  const dy = [0, 1, 0, -1];
  let visited = createArray(n + 1, m + 1, 2);
  const { startX, startY } = findStartPosition(maps, n, m);

  q.push({ x: startX, y: startY, time: 0, isLeverActive: false });
  while (q.length !== 0) {
    const { x, y, time, isLeverActive } = q.shift();

    if (maps[x][y] === CELL.goal && isLeverActive) {
      return time;
    }
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
        continue;
      }
      if (maps[nx][ny] === CELL.wall) {
        continue;
      }
      if (visited[nx][ny][isLeverActive]) {
        continue;
      }
      const nextIsLeverActive = isLeverActive || maps[nx][ny] === CELL.lever;
      visited[nx][ny][nextIsLeverActive] = true;
      q.push({ x: nx, y: ny, time: time + 1, isLeverActive: nextIsLeverActive });
    }
  }
  // error case
  return -1;
}

function solution(maps) {
  const n = maps.length;
  const m = maps[0].length;

  return bfs(maps, n, m);
}
