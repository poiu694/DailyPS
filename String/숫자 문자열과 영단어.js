const replaceAll = (str, target, replaceStr) => {
    return str.split(target).join(replaceStr);
};

function solution(s) {
    const numbers = ['zero', 'one', 'two', 'three', 'four', 'five',
                     'six', 'seven', 'eight', 'nine'];
    return parseInt(numbers.reduce((ans, now, i) => replaceAll(ans, now, i), s));
}