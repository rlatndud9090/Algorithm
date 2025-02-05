function solution(s)
{
    const str = `#${s.split('').join('#')}#`;
    const A = Array(str.length).fill(0);
    
    let p = -1; // 가장 오른쪽에 닿은 팰린드롬의 중심
    let r = -1; // 가장 오른쪽에 닿은 팰린드롬의 오른쪽 끝
    for (let i = 0; i < str.length; i += 1) {
        if (i <= r) {
            // 현재 인덱스가 p를 중심으로 하는 팰린드롬 안에 속함.
            A[i] = Math.min(A[2 * p - i], r - i);
        } else {
            // 현재 인덱스는 팰린드롬 안에 속하지 않았음. -> 새로 시작
            A[i] = 0;
        }
        
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < str.length && str[i - A[i] - 1] === str[i + A[i] + 1]) {
            // A[i] 까지는 팰린드롬 확정이고, 한칸씩 넓혀가면서 A[i]가 늘어날 수 있을때까지 늘림
            A[i] += 1;
        }
        
        if (i + A[i] > r) {
            // 이전까지의 어떤 팰린드롬보다 오른쪽으로 갔다면 갱신하기.
            r = i + A[i];
            p = i;
        }
    }
    
    const max = Math.max(...A);
    
    return max;
}