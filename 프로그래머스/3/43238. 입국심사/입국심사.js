function solution(n, times) {
    let left = 1;
    let right = Math.max(...times) * n;
    
    let result = right;
    
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        
        const count = times.reduce((acc, time) => acc + Math.floor(mid / time), 0);
        
        if (count >= n) { // 시간이 남는다 -> 더 작은 시간 탐색
            result = mid;
            right = mid - 1;
        } else { // 시간이 부족하다 -> 더 많은 시간 탐색
            left = mid + 1;
        }
    }
    
    return result;
}