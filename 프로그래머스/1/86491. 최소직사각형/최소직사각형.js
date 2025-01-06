function solution(sizes) {
    var answer = 0;
    return sizes.reduce((acc, size) => {
        const sorted = size.sort((a, b) => a-b);
        acc[0] = Math.max(acc[0], sorted[0]);
        acc[1] = Math.max(acc[1], sorted[1]);
        return acc;
    }, [0, 0]).reduce((a,e)=> a *= e);
}