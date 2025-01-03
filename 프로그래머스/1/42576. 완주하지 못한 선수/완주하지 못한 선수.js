function solution(participant, completion) {
    let answer = '';
    const compMap = new Map();
    const partMap = new Map();
    for (const compRunner of completion) {
        if (compMap.has(compRunner)) {
            compMap.set(compRunner, compMap.get(compRunner) + 1);
        } else {
            compMap.set(compRunner, 1);
        }
    }
    for (const partRunner of participant) {
        if (partMap.has(partRunner)) {
            partMap.set(partRunner, partMap.get(partRunner) + 1);
        } else {
            partMap.set(partRunner, 1);
        }
    }
    for (const runner of partMap.keys()) {
        if (!compMap.has(runner) || partMap.get(runner) !== compMap.get(runner)) {
            answer = runner;
            break;
        } 
    }
    return answer;
}