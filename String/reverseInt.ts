const safeParseInt = (x: string): number => {
  const intMax = Math.pow(2, 31) - 1;
  const intMin = intMax * -1 + 1;
  const parsed = parseInt(x);

  if (isNaN(parsed)) return 0;
  if (parsed > intMax || parsed < intMin) return 0;
  return parsed;
};

function reverse(x: number): number {
  let sign = x < 0 ? -1 : 1;
  return sign * safeParseInt(x.toString().split('').reverse().join(''));
}
