const NUMBER_POSITION = {
  1: [0, 0],
  2: [0, 1],
  3: [0, 2],
  4: [1, 0],
  5: [1, 1],
  6: [1, 2],
  7: [2, 0],
  8: [2, 1],
  9: [2, 2],
  '*': [3, 0],
  0: [3, 1],
  '#': [3, 2],
};

const MAX = 2147483654;

function make(dim, lvl, arr) {
  if (lvl === 1) return [];
  if (!lvl) lvl = dim;
  if (!arr) arr = [];
  for (var i = 0, l = dim; i < l; i += 1) {
    arr[i] = make(dim, lvl - 1, arr[i]);
  }
  return arr;
}

const getDistanceByKeyPosition = (position1, position2) => {
  if (position1.length > 0 && position2.length > 0)
    return (
      Math.abs(position1[0] - position2[0]) +
      Math.abs(position1[1] - position2[1])
    );
};

const getCurrentScoreByKeyPosition = (position1, position2) => {
  let xDiff = Math.abs(position1[0] - position2[0]);
  let yDiff = Math.abs(position1[1] - position2[1]);
  if (xDiff === 0 && yDiff === 0) {
    return 1;
  }

  let sum = 0;
  while (xDiff > 0 && yDiff > 0) {
    // 대각선
    sum += 3;
    xDiff--;
    yDiff--;
  }
  while (xDiff > 0) {
    sum += 2;
    xDiff--;
  }
  while (yDiff > 0) {
    sum += 2;
    yDiff--;
  }
  return sum;
};

function solution(numbers) {
  const leftKey = 4;
  const rightKey = 6;
  const n = numbers.length;
  let minLength = MAX;
  const visited = new Map();

  const dfs = (index, leftKey, rightKey) => {
    const leftPosition = NUMBER_POSITION[leftKey];
    const rightPosition = NUMBER_POSITION[rightKey];
    const visitedIndex = `${index}${leftKey}${rightKey}`;
    if (index === n) {
      return 0;
    }
    if (visited.has(visitedIndex)) {
      return visited.get(visitedIndex);
    }
    const target = numbers[index];

    const targetPosition = NUMBER_POSITION[numbers[index]];
    const leftDistance = getDistanceByKeyPosition(leftPosition, targetPosition);
    const rightDistance = getDistanceByKeyPosition(
      rightPosition,
      targetPosition
    );

    let leftScore = MAX;
    let rightScore = MAX;
    if (leftKey !== target) {
      // right move
      const sum = getCurrentScoreByKeyPosition(rightPosition, targetPosition);
      leftScore = dfs(index + 1, leftKey, target) + sum;
    }
    if (rightKey !== target) {
      // left move
      const sum = getCurrentScoreByKeyPosition(leftPosition, targetPosition);
      rightScore = dfs(index + 1, target, rightKey) + sum;
    }
    visited.set(visitedIndex, Math.min(leftScore, rightScore));
    return visited.get(visitedIndex);
  };

  return dfs(0, leftKey, rightKey);
}
