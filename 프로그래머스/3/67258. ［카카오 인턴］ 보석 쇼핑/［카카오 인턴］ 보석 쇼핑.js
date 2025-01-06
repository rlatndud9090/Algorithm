function solution(gems) {
    const uniqueGems = new Set(gems);
    const gemCount = uniqueGems.size;
    const gemMap = new Map();
    let left = 0;
    let minLength = Infinity;
    let result = [0, 0];

    for (let right = 0; right < gems.length; right++) {
        const rightGem = gems[right];
        gemMap.set(rightGem, (gemMap.get(rightGem) || 0) + 1);

        while (gemMap.size === gemCount) {
            const currentLength = right - left + 1;
            if (currentLength < minLength) {
                minLength = currentLength;
                result = [left + 1, right + 1];
            }

            const leftGem = gems[left];
            gemMap.set(leftGem, gemMap.get(leftGem) - 1);
            if (gemMap.get(leftGem) === 0) {
                gemMap.delete(leftGem);
            }
            left++;
        }
    }

    return result;
}