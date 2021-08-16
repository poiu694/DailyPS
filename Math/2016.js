function getDays(a, b) {
    const month_days = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    if(a < 2) {
        return b - 1;
    } else {
        return month_days.slice(0, a-1).reduce((a,b) => a + b) + b - 1;
    }
}

function getDays2(a,b) {
    const date = new Date(`2016-${a}-${b}`);
    return date.getDay();
}

function solution(a, b) {
    const days = ["FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"];
    console.log(getDays2(a,b));
    return days[(getDays(a,b)) % 7];
}