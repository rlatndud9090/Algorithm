function solution(progresses, speeds) {
    const answer = [];
    const requires = [];
    for (let i = 0; i < progresses.length; i++) {
        const progress = progresses[i];
        const speed = speeds[i];
        requires.push(Math.ceil((100 - progress) / speed));   
    }
    answer.push(1);
    let prevReq = requires[0];
    for (let i = 1; i < requires.length; i++) {
        const req = requires[i];
        if (req > prevReq) {
            answer.push(1);
            prevReq = req;
        } else {
            answer[answer.length - 1] += 1;
        }
    }
    return answer;
}