function solution(n, costs) {
    costs.sort((a,b) => a[2] - b[2]); // 비용 오름차순 정렬
    
    const parent = new Array(n).fill(0).map((_, i) => i); // Union-Find
    
    const getRoot = (i) => {
        if (parent[i] === i) {
            return i;
        }
        return getRoot(parent[i]);
    }
    
    const union = (i, j) => {
        const rootOfI = getRoot(i);
        const rootOfJ = getRoot(j);
        
        if (rootOfI !== rootOfJ) {
            parent[rootOfJ] = rootOfI;
            return true;
        }
        return false;
    }
    
    let result = 0;
    let connectedNodes = 0;
    
    for (const [i, j, val] of costs) {
        if (union(i, j)) {
            result += val;
            connectedNodes += 1;
            if (connectedNodes === n - 1) {
                break;
            }
        }
    }
    
    return result;
    
}