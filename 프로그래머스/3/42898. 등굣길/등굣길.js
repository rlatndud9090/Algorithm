function solution(m, n, puddles) {
    const MOD = 1_000_000_007;
    const dp = Array.from({ length: n + 1 }, () => Array(m + 1).fill(0));

    puddles.forEach(([x, y]) => dp[y][x] = -1);

    dp[1][1] = 1;

    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= m; j++) {
            if (dp[i][j] === -1) {
                dp[i][j] = 0;
                continue;
            }
            if (i > 1) dp[i][j] += dp[i - 1][j] % MOD;
            if (j > 1) dp[i][j] += dp[i][j - 1] % MOD;
            dp[i][j] %= MOD;
        }
    }

    return dp[n][m];
}