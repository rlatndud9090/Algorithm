function solution(priorities, location) {
    let answer = 0;
    const pairs = priorities.map((val, index) => {
        return [index, val];
    });
    while (pairs.length > 0) {
        const front = pairs.shift();
        if (pairs.some(pair => pair[1] > front[1])) {
            pairs.push(front);
        } else {
            answer += 1;
            if (front[0] === location) {
                return answer;
            }
        }
    }
    return answer;
}