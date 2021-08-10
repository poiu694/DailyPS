function get_dist(hand_index, number_index, flag) {
    // hand가 가운데에 있으면
    if (flag) {
        return Math.abs(hand_index - number_index);
    } 
    // hand가 양 옆에 있으면
    else {
        return Math.abs(hand_index - number_index) + 1;
    }
}

function solution(numbers, hand) {
    numbers = numbers.map(number => number === 0 ? 11 : number);
    
    const left_key = [1, 4, 7, 10];
    const center_key = [2, 5, 8, 11];
    const right_key = [3, 6, 9, 12];
    
    // Start hand loc
    let left_hand = 10;
    let right_hand = 12;
    
    // answer
    let answer = "";
    for (const number of numbers){
        const left_index = left_key.indexOf(number);
        const right_index = right_key.indexOf(number);
        const center_index = center_key.indexOf(number);
        
        // to Left
        if (left_index !== -1) {
            answer += "L";
            left_hand = number;
        }
        // to Right
        else if (right_index !== -1) {
            answer += "R";
            right_hand = number;
        }
        // to Center
        else {
            const left_flag = center_key.indexOf(left_hand) === -1 ? false : true;
            const right_flag = center_key.indexOf(right_hand) === -1 ? false : true;
            
            const left_hand_index = left_flag ? center_key.indexOf(left_hand) : left_key.indexOf(left_hand);
            const right_hand_index = right_flag ? center_key.indexOf(right_hand) : right_key.indexOf(right_hand);
            
            const left_dist = get_dist(left_hand_index, center_index, left_flag);
            const right_dist = get_dist(right_hand_index, center_index, right_flag);
            
            // left_dist < right_dist : select left_hand
            if (left_dist < right_dist) {
                answer += "L";
                left_hand = number;
            } 
            // left_dist > right_dist : select right_hand
            else if (left_dist > right_dist) {
                answer += "R";
                right_hand = number;
            }
            // left_dist === right_dist : select main hand
            else {
                if (hand === "left") {
                    answer += "L";
                    left_hand = number;
                } else {
                    answer += "R";
                    right_hand = number;
                }
            }
        }
    }
    return answer;
}