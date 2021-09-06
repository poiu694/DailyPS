function solution(weights, head2head) {
  return head2head
    .map((l, i) =>
      l.split("").reduce(
        (acc, v, j) => {
          acc[0] += v === "W" ? 1 : 0;
          acc[1] += v === "W" ? (weights[i] < weights[j] ? 1 : 0) : 0;
          acc[2] += v === "L" ? 1 : 0;
          return acc;
        },
        [0, 0, 0]
      )
    )
    .map((v) => [v[0] / (v[0] + v[2]), v[1]])
    .map((v, i) => [i + 1, { t: v[0], s: v[1], w: weights[i] }])
    .sort(
      (a, b) =>
        b[1].t - a[1].t || b[1].s - a[1].s || b[1].w - a[1].w || a[0] - b[0]
    )
    .map((v) => v[0]);
}
