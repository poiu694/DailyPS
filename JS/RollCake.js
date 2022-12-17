function solution(toppings) {
  const map1 = new Map();
  const map2 = new Map();

  // 일단 한 쪽으로 다 몰아넣음
  for (const topping of toppings) {
    map1.set(topping, map1.has(topping) ? map1.get(topping) + 1 : 1);
  }

  let answer = 0;
  for (const topping of toppings) {
    // 맨 왼쪽부터 하나씩 오른쪽으로 옮겨본다.
    map2.set(topping, map2.has(topping) ? map2.get(topping) + 1 : 1);
    if (map1.get(topping) > 1) {
      map1.set(topping, map1.get(topping) - 1);
    } else {
      // map1이 하나라면 프로퍼티를 삭제한다.
      map1.delete(topping);
    }
    if (map1.size === map2.size) {
      answer++;
    }
  }
  return answer;
}
