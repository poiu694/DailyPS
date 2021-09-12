function get_prime_list() {
  const visited = Array(3005).fill(false);
  const prime_list = [];
  for (let i = 2; i <= 3005; i++) {
    for (let j = i * i; j <= 3005; j += i) {
      if (!visited[j]) visited[j] = true;
    }
  }

  for (let i = 2; i <= 3005; i++) {
    if (!visited[i]) prime_list.push(i);
  }

  return prime_list;
}

function solution(nums) {
  const prime_list = get_prime_list();
  let cnt = 0;

  for (let i = 0; i < nums.length - 2; i++) {
    for (let j = i + 1; j < nums.length - 1; j++) {
      for (let k = j + 1; k < nums.length; k++) {
        const target = nums[i] + nums[j] + nums[k];
        if (prime_list.indexOf(target) != -1) cnt++;
      }
    }
  }

  return cnt;
}
