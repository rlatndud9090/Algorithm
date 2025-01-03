function solution(s){
    var answer = true;
    
    const stack = [];
    
    s.split('').forEach(ch => {
        if (ch === '(') {
            stack.push(ch);
        } else if (ch === ')') {
            const lastCh = stack.pop();
            if (lastCh !== '(') {
                answer = false;
            }
        } else {
            answer = false;
        }
    });
    if (stack.length > 0) {
        answer = false;
    }
    
    return answer;
}