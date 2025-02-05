function solution(n, vertex) {
    const graph = Array.from({length: n + 1}, ()=>[]);
    

    
    vertex.forEach((edge) => {
        const [x, y] = edge;
        
        graph[x].push(y);
        graph[y].push(x);
        
    });
    
    const queue = [1];
    const visited = new Set([1]);
    const distance = Array(n+1).fill(0);
    
    while (queue.length) {
        const node = queue.shift();
        
        for (const next of graph[node]) {
            if (!visited.has(next)) {
                queue.push(next);
                visited.add(next);
                distance[next] = distance[node] + 1;
            }
        }
    }
    
    const max = Math.max(...distance);
    
    return distance.filter(node => node === max).length;
}