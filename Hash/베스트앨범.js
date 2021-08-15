function solution(genres, plays) {
    const play_list = genres.reduce((acc, cur, index) => {
      if(!acc[cur]) {
         acc[cur] = {
             play: 0,
             list: [],
         };
      }
      acc[cur].play += plays[index];
      acc[cur].list.push([{
          index: index,
          play: plays[index],
      }]);
      return acc;
    }, {});
    
    const ans = Object.values(play_list)
                .sort((a, b) => b.play - a.play);
    ans.forEach((e, i) => e.list.sort((a, b) => b[0].play - a[0].play));
    ans.forEach((e) => e.list.splice(2));
    const answer = ans.map((now, i) => now.list.map((row) => row[0].index));
    return answer.flat();
}