// 2554
// 1000, 1000, 100, 100, 100, 100, 100, 10, 10, 10, 10, 10, 1, 1, 1, 1
function solution(storey) {
    let result = 0;
    let flag = false;
    while (storey) {
        if (storey % 10 < 5) {
            result += storey % 10;
        } else if (storey % 10 === 5) {
            result += 5;
            if ((Math.floor(storey / 10)) % 10 >= 5) {
                storey += 5;
            }
        } else {
            result += (10 - (storey % 10))
            storey += 10;
        }
        storey = Math.floor(storey / 10);
    }
    
    return result;
}