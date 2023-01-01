const currentTime = '12:05';

function diffMinute(time1, time2) {
  const [hour1, minute1] = time1.split(':');
  const [hour2, minute2] = time2.split(':');
  if (minute2 > minute1) {
    // 12:05, 13:25
    return (hour2 - hour1) * 60 + (minute2 - minute1);
  }
  // 12:05, 13:00
  return (hour2 - hour1) * 60 - (minute1 - minute2);
}

function solution(bakerySchedule, number, discount) {
  const K = discount[0];
  const validBakerySchedules = bakerySchedule
    .map((schedule) => {
      const info = schedule.split(' ');
      return {
        time: info[0],
        quantity: info[1],
      };
    })
    .filter((info) => info.time >= currentTime);

  let cntSoldBread = 0;
  for (let i = 0; i < validBakerySchedules.length; i++) {
    cntSoldBread += Number(validBakerySchedules[i].quantity);
    if (cntSoldBread >= K) {
      return diffMinute(currentTime, validBakerySchedules[i].time);
    }
    console.log(cntSoldBread);
  }
  return -1;
}
