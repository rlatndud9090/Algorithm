function solution(begin, target, words) {
    const visited = new Set();
    
    const canConvert = (a, b) => {
        return a.split('').reduce((acc, char, index) => {
            return acc + (char !== b[index] ? 1 : 0);
        }, 0) === 1;
    }
    
    const bfs = (begin) => {
        const queue = [];
        queue.push([begin, 0]);
        while (queue.length) {
            const [curWord, count] = queue.shift();
            if (curWord === target) {
                return count;
            }
            words.forEach(word => {
                if (!visited.has(word) && canConvert(word, curWord)) {
                    visited.add(word);
                    queue.push([word, count+1]);
                }
            });
        }
        return 0;
    }
    
    return bfs(begin);
}