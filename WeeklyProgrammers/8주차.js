function solution(sizes) {
  return sizes
    .reduce(
      ([w, h], [a, b]) => [
        (w = Math.max(w, Math.min(a, b))),
        Math.max(h, Math.max(a, b)),
      ],
      [0, 0]
    )
    .reduce((ans, v) => ans * v, 1);
}
