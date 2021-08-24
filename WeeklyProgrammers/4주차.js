function solution(table, languages, preference) {
    return table.map((r) => r.split(' '))
                .map((t) => [...t.splice(0, 1), t])
                .map(([t, arr]) => [t,
                     languages.reduce((acc, l, i)=> {
                        acc += (5 - (arr.indexOf(l) === -1 ? 5 : arr.indexOf(l)))
                                    * preference[i];
                        return acc;
                     }, 0)])
                .sort((a, b) => b[1] - a[1] - (a[0] < b[0]))[0][0]
}