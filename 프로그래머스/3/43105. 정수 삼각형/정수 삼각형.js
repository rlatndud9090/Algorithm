function solution(triangle) {
    const height = triangle.length;
    const dp = Array.from({ length: height }, (_, i) => Array(i + 1).fill(0));
    for (let i = 0; i < height; i++) {
        for (let j = 0; j < i+1; j++) {
            const prevLeft = i !== 0 && j !== 0 ? dp[i-1][j-1] : 0;
            const prevRight = i !== 0 && j !== i ? dp[i-1][j] : 0;
            dp[i][j] = triangle[i][j] + Math.max(prevLeft, prevRight);
        }
    }
    return Math.max(...dp[height-1]);
}