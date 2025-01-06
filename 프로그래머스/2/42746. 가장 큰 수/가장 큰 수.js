function solution(numbers) {
    const sorted = numbers
        .map(String)
        .sort((a, b) => (b + a) - (a + b));

    const result = sorted.join('');
    
    return result[0] === '0' ? '0' : result;
}