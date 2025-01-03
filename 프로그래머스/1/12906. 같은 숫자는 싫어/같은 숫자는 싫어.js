function solution(arr)
{
    const answer = [];
    
    answer.push(arr[0]);
    
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] !== answer[answer.length-1]) {
            answer.push(arr[i]);
        }
    }
    
    return answer;
}