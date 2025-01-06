function solution(n, computers) {
    const visited = new Set();
    let network = 0;
    
    const bfs = (num) => {
        const queue = [];
        queue.push(num);
        while (queue.length) {
            const cur = queue.shift();
            computers[cur].forEach((connect, index) => {
                if (connect === 1 && !visited.has(index)) {
                    visited.add(index);
                    queue.push(index);
                }
            });
        }
    };
    
    for (let i = 0; i < n; i++) {
        if (!visited.has(i)) {
            visited.add(i);
            bfs(i);
            network += 1;
        }
    }
    
    return network;
}