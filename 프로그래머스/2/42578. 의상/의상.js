function solution(clothes) {
    const clMap = new Map();
    for (const clothe of clothes) {
        const type = clothe[1];
        clMap.set(type, (clMap.get(type) || 0) + 1);
    }
    let answer = 1;
    for (const count of clMap.values()) {
        answer *= count + 1;
    }
    return answer - 1;
}