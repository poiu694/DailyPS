function solution(data, col, row_begin, row_end) {
  const primaryIndex = 0;
  const sortedIndex = col - 1;
  // condition2, sort
  data.sort((a, b) => {
    if (a[sortedIndex] === b[sortedIndex]) {
      return b[primaryIndex] - a[primaryIndex];
    }
    return a[sortedIndex] - b[sortedIndex];
  });
  // condition3, S_i
  const sArray = data.map((row, idx) => {
    return row.reduce((acc, cell) => acc + (cell % (idx + 1)), 0);
  });
  // condition4, row_begin <= i <= row_end
  const answer = sArray.reduce((acc, cell, idx) => {
    if (row_begin <= idx + 1 && idx + 1 <= row_end) {
      acc ^= cell;
    }
    return acc;
  }, 0);
  return answer;
}
