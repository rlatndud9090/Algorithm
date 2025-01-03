function solution(nums) {
    let answer = 0;
    const numSet = new Set(nums);
    if (numSet.size > nums.length / 2) {
        answer = nums.length / 2;
    } else {
        answer = numSet.size;
    }
    return answer;
}