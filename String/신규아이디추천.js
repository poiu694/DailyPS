function solution(new_id) {
    // to Lower Case
    const step_one = new_id.toLowerCase();
    const step_two = step_one.replace(/[^a-z0-9-_.]/g, "");
    const step_three = step_two.replace(/\.+/g, ".");
    const step_four = step_three.replace(/^\.|\.$/g, "");
    const step_five = step_four.length > 0 ? step_four : "a";
    const step_six = step_five.length >= 16 ? step_five.slice(0, 15).replace(/\.$/g, "") : step_five;
    const step_seven = step_six.length <= 2 ?
            step_six + step_six.charAt(step_six.length - 1).repeat(3 - step_six.length) 
            : 
            step_six;
    return step_seven;
}